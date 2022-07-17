# Using https://pypi.org/project/leb128/
import leb128
bytes = leb128.i.encode(-1215)

newFile = open("number", "wb")
newFileByteArray = bytearray(bytes)
newFile.write(newFileByteArray)
