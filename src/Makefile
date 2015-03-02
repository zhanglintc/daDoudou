
# VPATH = C:\\Program\ Files\\Microsoft\ Visual\ Studio\ 9.0\\VC\\include
obj = affix.obj dadoudou.obj doudouGen.obj SourceMain.obj
head = headers.h stdafx.h

ddAPP: $(obj)
	cl -o run $(obj)

dadoudou.obj: $(head)
	cl -c dadoudou.cpp
affix.obj: $(head)
	cl -c affix.cpp
doudouGen.obj: $(head)
	cl -c doudouGen.cpp
SourceMain.obj: $(head)
	cl -c SourceMain.cpp


.PHONY: clean
clean:
	rm *.obj

