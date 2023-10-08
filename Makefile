off:
	gcc offthemarket.c -no-pie -o astral-avenue
	patchelf --set-interpreter /tmp/ld-2.23.so ./astral-avenue

clean:
	rm astral-avenue


