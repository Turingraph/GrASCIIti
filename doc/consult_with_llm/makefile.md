my previous solution

```
lib/%.a: $$(BUILD_$(patsubst $(@D)/%.a,%,$@))
	echo $$(BUILD_$(patsubst $(@D)/%.a,%,$@))
	@mkdir -p $(@D)
	ar rcs $@ $^
```

ChatGPT said that my solution isn't working because `$` inside
`BUILD_$(patsubst $(@D)/%.a,%,$@)` is activated too early.
The reason that echo print something is because
Makefile create the variable name for Shell, but not for Makefile themselves.

ChatGPT recommended me to use notdir and basename command.

`$(notdir names...)`
Extracts all but the directory-part of each file name in names. 
If the file name contains no slash, it is left unchanged. 

`$(basename names...)`
extracts all but the suffix of each file name in names.

Even if my solution were working correctly, 
ChatGPT solution in this case work better because 
it use shortcut from notdir and basename command, which improve readability,
and thus easier to maintain.

The takes away is reading the functions for files name section of Makefile manual first
(a.k.a. https://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_node/make_79.html )
if you have to manipulating the string of the files/folders name according to correct 
format like this, for example you might want to split string as arrays of string,
with `,` or `/` as the separators.
