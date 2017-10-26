INSTALL_PATH= /usr/local
JSON_INCLUDE= $(INSTALL_PATH)/include/libjson

CPP= g++
CPPDEFINES= -D_GNU_SOURCE -D_REENTRANT
CPPINCLUDES= 
CPPFLAGS= -Wall -g -std=c++11 -MMD -fPIC $(CPPDEFINES) $(CPPINCLUDES)

LD= g++
LDPATHS= 
LDLIBS= -lcoder
LDFLAGS= -Wall -g -shared -Wl,--no-undefined $(LDPATHS) $(LDLIBS)

CPP_SOURCES= Array.cc ArrayParser.cc ArrayVariant.cc BaseVariant.cc \
			 BooleanParser.cc Document.cc NamedValueParser.cc NullParser.cc \
			 NumberParser.cc Object.cc ObjectParser.cc ObjectVariant.cc \
			 ParsedArray.cc ParseList.cc ParsedObject.cc Parser.cc ParserBase.cc \
			 ParserStart.cc ParsedStack.cc StringParser.cc ValueParser.cc Variant.cc

PUBLIC_HEADERS= Array.h Document.h Exception.h Object.h ParseException.h Variant.h \
				VariantException.h

CPP_OBJECT= $(CPP_SOURCES:.cc=.o)
DEPEND= $(CPP_OBJECT:.o=.d)

.PHONY: clean install

LIBRARY= libjson.so

all: $(LIBRARY)

$(CPP_OBJECT): %.o: %.cc
	$(CPP) -c $(CPPFLAGS) -o $@ $<

$(LIBRARY): $(CPP_OBJECT)
	    $(LD) -o $@ $(CPP_OBJECT) $(LDFLAGS)

clean:
	-rm -f $(CPP_OBJECT) $(DEPEND) $(LIBRARY)

install:
	rm -rf $(JSON_INCLUDE)
	mkdir -p $(JSON_INCLUDE)
	cp --preserve=timestamps $(PUBLIC_HEADERS) $(JSON_INCLUDE)
	chmod 755 $(JSON_INCLUDE)
	chmod 644 $(JSON_INCLUDE)/*
	chown -R root:root $(JSON_INCLUDE)
	cp --preserve=timestamps $(LIBRARY) $(INSTALL_PATH)/lib64
	chmod 755 $(INSTALL_PATH)/lib64/$(LIBRARY)
	chown root:root $(INSTALL_PATH)/lib64/$(LIBRARY)

-include $(DEPEND)
