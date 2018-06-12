.PHONY: all
all:
	@echo "Nothing to do"
.PHONY: install
install: libgen-test.sh libgen.io.sh install-libgen.sh move-libgen.sh
	test -n ""$(DEST) || exit 1
	install libgen-test.sh $(DEST)/libgen-test
	install libgen.io.sh $(DEST)/libgen.io
	install install-libgen.sh $(DEST)/install-libgen
	install move-libgen.sh $(DEST)/move-libgen
