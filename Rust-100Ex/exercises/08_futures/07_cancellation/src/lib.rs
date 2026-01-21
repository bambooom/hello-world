// TODO: fix the `assert_eq` at the end of the tests.
//  Do you understand why that's the resulting output?
use std::time::Duration;
use tokio::io::AsyncReadExt;
use tokio::net::TcpListener;

pub async fn run(listener: TcpListener, n_messages: usize, timeout: Duration) -> Vec<u8> {
    let mut buffer = Vec::new();
    for _ in 0..n_messages {
        let (mut stream, _) = listener.accept().await.unwrap();
        let _ = tokio::time::timeout(timeout, async {
            stream.read_to_end(&mut buffer).await.unwrap();
        })
        .await;
    }
    buffer
}

#[cfg(test)]
mod tests {
    use super::*;
    use tokio::io::AsyncWriteExt;

    #[tokio::test]
    async fn ping() {
        let listener = TcpListener::bind("127.0.0.1:0").await.unwrap();
        let addr = listener.local_addr().unwrap();
        let messages = vec!["hello", "from", "this", "task"];
        let timeout = Duration::from_millis(20);
        let handle = tokio::spawn(run(listener, messages.len(), timeout.clone()));

        for message in messages {
            let mut socket = tokio::net::TcpStream::connect(addr).await.unwrap();
            let (_, mut writer) = socket.split();

            // split the message in two halves, first half will be sent, then sleep for a while, then send the second half
            let (beginning, end) = message.split_at(message.len() / 2);

            // Send first half
            writer.write_all(beginning.as_bytes()).await.unwrap();
            // sleep for a while, longer than the timeout
            tokio::time::sleep(timeout * 2).await; // 40ms, twice the server timeout, so `read_to_end` will timeout
            // send the second half
            writer.write_all(end.as_bytes()).await.unwrap();

            // Close the write side of the socket
            let _ = writer.shutdown().await;
        }

        // 在客户端睡眠期间，服务器那一侧的 read_to_end 先超时退出，缓冲里只留下已经读到的前半段内容。下一轮循环虽然继续监听新的连接，但共享的 buffer 已经累积了这些不完整的数据，最终测试得到的就是拼接后的 hefrthta

        let buffered = handle.await.unwrap();
        let buffered = std::str::from_utf8(&buffered).unwrap();
        assert_eq!(buffered, "hefrthta");
    }
}
