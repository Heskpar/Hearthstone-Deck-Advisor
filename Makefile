objs = main.o getCard.o getData.o GUIWindow.o makeDisplayWindow.o compareSpell.o\
	cullCards.o compareMinions.o cbSearch.o compareWeapons.o
CXXFLAGS = -std=c++11 -g -I ~/fltk-1.3.3/ \
	`fltk-config --cxxflags --ldflags --use-cairo --use-images`
LDFLAGS = -lcurl

lab: ${objs} lab.h
	g++ ${CXXFLAGS} ${objs} -o lab ${LDFLAGS} 

doc: ${objs: .o=.cpp} lab.h
	for f in ${objs:%.o=%}; do \
		lgrind -i -o $$f.tex $$f.cpp; \
	done
	latex lab.tex
	dvips lab.dvi
	ps2pdf lab.ps
	gv lab.pdf &
