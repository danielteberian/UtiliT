all: asciitab dumph timedisp



asciitab: asciitab
	cc src/utilities/asciitab/asciitab.c -o out/asciitab

dumph: dumph
	cc src/utilities/dumph/dumph.c -o out/dumph

timedisp: timedisp
	cc src/utilities/timedisp/timedisp.c -o out/timedisp
