CC = gcc
OUTPUT = build
OBJS = \
	  binary_search.elf \

test: $(OBJS)

%.elf: %.c $(OUTPUT)
	$(CC) $< -o $(OUTPUT)/$@

$(OUTPUT):
	mkdir $(OUTPUT)

clean:
		rm -rf $(OUTPUT)
