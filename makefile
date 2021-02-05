CFLAGS=--std=c18 -pedantic-errors -Wall -Werror -Iinclude/ -Isrc/
BUILDDIR=build
SRCDIR=src
CC=gcc

all: $(BUILDDIR)/dates.o $(BUILDDIR)/rooms.o $(BUILDDIR)/janitors.o $(BUILDDIR)/main.o
	$(CC) -o make-duty $^

build:
	mkdir $(BUILDDIR)

$(BUILDDIR)/dates.o: $(SRCDIR)/dates.c build
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILDDIR)/rooms.o: $(SRCDIR)/rooms.c build
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILDDIR)/janitors.o: $(SRCDIR)/janitors.c build
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILDDIR)/main.o: $(SRCDIR)/main.c build
	$(CC) -c $(CFLAGS) $< -o $@

clean : 
	rm -rf $(BUILDDIR) make-duty