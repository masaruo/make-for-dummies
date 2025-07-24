# level fdf

## issue
```
.
├── Makefile
├── fakelibx
│   ├── Makefile
│   └── fake.c
│   └── fake.h
├── includes
│   └── fdf.h
└── src
    ├── main.c
    └── process
        ├── parse
        │   └── parse.c
        └── process.c
```
- [ ] more complicated `src` structure
- [ ] ライブラリ

---
## basic
### vpath
* いいよね？！
---
### how to call other Make?
* `make <command> -C <dir>` で違う場所にいるmakeの実行
---
### library
* `*.h` どこでつかう？
* `-L`　ライブラリを探す場所。どこで指定する？
* `-l`　リンクするライブラリ、`libfake.a` -> `-lfake`でOK
---
