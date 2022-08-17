
CC = /usr/bin/g++ -D DEBUG
CFLAGS = -lboost_log -lboost_system -lcurl -lpthread -lcrypto -ldl -lssl -ltbb -lz -lOneXAPI
LOCAL_INC = -L$(PWD) -Wl,-rpath=$(PWD) -I$(PWD)/../OneXDev/include
LOCAL_OPTIONS = -fdiagnostics-color=always -DBOOST_LOG_DYN_LINK -g
PROGRAM_NAME = main
SRCDIR       = src/
OBJDIR       = tmp/
rwildcard    = $(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))
OFILES       = $(patsubst %.cpp,%.o,$(call rwildcard,./tmp,*.cpp)) $(patsubst %.cpp,%.o,$(wildcard ./*.cpp))


vpath %.cpp tmp
vpath %.o tmp

compileAndRun:
	mkdir -p $(OBJDIR)
	cp -r -p $(wildcard $(SRCDIR)*) $(OBJDIR)
	@make -s $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OFILES)
	echo $(CC) $(LOCAL_OPTIONS) $(LOCAL_INC) $(CFLAGS) -o $(PROGRAM_NAME) $(OFILES)
	$(CC) $(LOCAL_OPTIONS) -o $(PROGRAM_NAME) $(OFILES) $(LOCAL_INC) $(CFLAGS) 

%.o: %.cpp
	echo $(CC) $(LOCAL_OPTIONS) $(LOCAL_INC) $(CFLAGS) -c -o $@ $<
	$(CC) $(LOCAL_OPTIONS) $(LOCAL_INC) $(CFLAGS) -c -o $@ $<