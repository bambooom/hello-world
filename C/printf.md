# some `printf` notes

## escape codes

> https://www.freebsd.org/cgi/man.cgi?printf

- `\a`	   Write a <bell> character.
- `\b`	   Write a <backspace> character.
- `\f`	   Write a <form-feed> character.
- `\n`	   Write a <new-line> character.
- `\r`	   Write a <carriage return> character.
- `\t`	   Write a <tab> character.
- `\v`	   Write a <vertical tab> character.
- `\'`	   Write a <single quote> character.
- `\\`	   Write a backslash character.
- `\num`	 Write a byte	whose value is the 1-, 2-, or 3-digioctal number `num`.	Multibyte characters can be constructed	using multiple `\num` sequences.

## format of the string

<code>
% [<i>zero or more</i> <b>flags</b>]
[<i>an optional minimum</i> <b>field width</b>]
[an optional <b>precision</b>]
[an optional <b>length modifier</b>]
<b>conversion specifier</b>
</code>


### format sequences (conversion specifier)

> https://www.man7.org/linux/man-pages/man3/printf.3.html

- `d, i`: The `int` argument is converted to signed decimal notation. The
  precision, if any, gives the minimum number of digits that must appear
- `o, u, x, X`: The `unsigned int` argument is converted to unsigned octal (`o`),
  unsigned decimal (`u`), or unsigned hexadecimal (`x` and `X`) notation.
- `e, E`: The `double` argument is rounded and converted in the style `[-]d.ddde±dd`
- `f, F`: The double argument is rounded and converted to decimal notation
  in the style `[-]ddd.ddd`, where the number of digits after the decimal-point
  character is equal to the precision specification.
- `g, G`: The `double` argument is converted in style `f` or `e` (or `F` or `E` for `G` conversions).
- `a, A`: For `a` conversion, the `double` argument is converted to hexadecimal
  notation (using the letters abcdef) in the style `[-]0xh.hhhhp±`;
  for `A` conversion the prefix `0X`, the letters ABCDEF, and the exponent separator `P` is used.
- `c`: If no `l` modifier is present, the `int` argument is converted to an `unsigned char`, and the resulting character is written.
- `s`, `n`, `m`, `%`...
