SRCDIR 	= src/
TESTDIR = test/
all:
	$(MAKE) -C $(SRCDIR)
	$(MAKE) -C $(TESTDIR)

.PHONY: clean
clean:
	$(MAKE) -C $(SRCDIR) clean
	$(MAKE) -C $(TESTDIR) clean

.PHONY: test
test:
	$(MAKE) -C $(TESTDIR) test

install:
	$(MAKE) -C $(SRCDIR) install

uninstall:
	$(MAKE) -C $(SRCDIR) uninstall
