
all: json-array json-object

json-array: json-array.o
	$(CC) -pedantic -Wall -Wextra json-array.o -o json-array

json-object: json-object.o
	$(CC) -pedantic -Wall -Wextra json-object.o -o json-object

appimagetool-x86_64.AppImage:
	wget https://github.com/AppImage/AppImageKit/releases/download/12/appimagetool-x86_64.AppImage
	chmod +x appimagetool-x86_64.AppImage

json-object-x86_64.AppImage: json-object appimagetool-x86_64.AppImage
	mkdir -p json-object.AppDir/usr/
	mkdir -p json-object.AppDir/usr/bin/
	mkdir -p json-object.AppDir/usr/lib/
	cp json-object json-object.AppDir/usr/bin/
	./appimagetool-x86_64.AppImage json-object.AppDir

json-array-x86_64.AppImage: json-array appimagetool-x86_64.AppImage
	mkdir -p json-array.AppDir/usr/
	mkdir -p json-array.AppDir/usr/bin/
	mkdir -p json-array.AppDir/usr/lib/
	cp json-array json-array.AppDir/usr/bin/
	./appimagetool-x86_64.AppImage json-array.AppDir

.PHONY: all
