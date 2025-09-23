
cat Makefile > current-code.md
cat header_files/*.h >> current-code.md
cat sources/*.c >> current-code.md
# cat sources/main.c >> current-code.md
# cat sources/[0-9]*.c | grep -v '^pu_' >> current-code.md
