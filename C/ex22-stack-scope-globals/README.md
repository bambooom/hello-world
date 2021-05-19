## Rules to follow realted to the stack

(to manage well about where variables live)

- Do not shadow a variable like in `scope_demo` with `count`, where you think
you're changing a value but actually not.
- Avoid using too many globals, especially across multiple files. Use accessor function
like `get_age`. Not apply to constants as those are read-only. Talking about variable like `THE_SIZE`.
- When in doubt, put it on the heap. Just create things with `malloc`.
- Don't use function static variables like `update_ratio`. Not very useful and cause pain.
- Avoid reusing function parameters. It's confusing whether you're just reusing it or if you think you're changing the caller's version of it.
