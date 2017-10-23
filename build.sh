#!/bin/sh
diet gcc \
	-nostdinc \
	-static \
	-s \
	-Os \
	-Wl,--gc-sections \
	-fno-ident \
	-fno-stack-protector \
	-fomit-frame-pointer \
	-ffunction-sections \
	-fdata-sections \
	-Wl,--gc-sections \
	-fno-unwind-tables \
	-fno-asynchronous-unwind-tables \
	-Wl,--build-id=none \
	wbsrv.c -o wbsrv
#strip -S \
#	--strip-unneeded \
#	--remove-section=.note.gnu.gold-version \
#	--remove-section=.comment \
#	--remove-section=.note \
#	--remove-section=.note.gnu.build-id \
#	--remove-section=.note.ABI-tag \
#	--remove-section=.jcr \
#	--remove-section=.got.plt \
#	--remove-section=.eh_frame \
#	--remove-section=.eh_frame_ptr \
#	wbsrv
sstrip -z wbsrv
