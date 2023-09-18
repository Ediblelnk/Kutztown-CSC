COMPILER  = g++

DEBUG  = -g

EXE  = app

HDRS  = WordData.h\
	WordDataList.h\
	WordCList.h\
	WordSTLSeq.h\
	WordList.h\

OBJS  = WordData.o\
	WordDataList.o\
	WordCList.o\
	WordSTLSeq.o\
	app.o\

SRC  = 	WordData.cpp\
	WordDataList.cpp\
	WordCList.cpp\
	WordSTLSeq.cpp\
	app.cpp\


##########################################################################
$(EXE): $(OBJS) $(HDRS) $(SRC)
	$(COMPILER) -o $(EXE) $(OBJS) $(DEBUG)

WordData.o:  WordData.cpp WordData.h 
	$(COMPILER) -c WordData.cpp $(DEBUG)

WordDataList.o:  WordDataList.cpp WordDataList.h WordList.h WordData.h
	$(COMPILER) -c WordDataList.cpp $(DEBUG)

WordCList.o:  WordCList.cpp WordCList.h CLinkedList.h WordList.h WordData.h
	$(COMPILER) -c WordCList.cpp $(DEBUG)

WordSTLSeq.o:  WordSTLSeq.h WordSTLSeq.cpp WordList.h WordData.h
	$(COMPILER) -c WordSTLSeq.cpp $(DEBUG)

app.o:  WordDataList.h WordList.h WordCList.h WordSTLSeq.h app.cpp 
	$(COMPILER) -c app.cpp $(DEBUG)

clean:
	rm *.o $(EXE)

