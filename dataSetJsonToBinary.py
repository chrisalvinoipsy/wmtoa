#!/usr/bin/env python

import sys
import json
import struct

def convertFile(inputFileName,outputFileName):
	with open(inputFileName,'r') as infile:
		with open(outputFileName,'wb') as outfile:
			s = ''
			objectCount = 0
			openBraceCount = 0
			closeBraceCount = 0
			for line in infile:
				if objectCount % 10000 == 0:
					print str(objectCount)
				s += line
				openBraceCount = openBraceCount + line.count('{')
				closeBraceCount = closeBraceCount + line.count('}')
				if openBraceCount == closeBraceCount:
					# first pass through write the number of entries expected
					j = json.loads(s)
					userID = str(j['value']['userId'])
					features = j['value']['features']
					if objectCount == 0:
						outfile.write(struct.pack('<i',len(features)))
					objectCount += 1
					closeBraceCount = 0 
					openBraceCount = 0
					s = ''
					outfile.write(struct.pack('<i',len(userID)))
					outfile.write(struct.pack('<s',userID))
					for x in features:
						outfile.write(struct.pack('<f',float(x)))

def main(args):
	if not len(args) == 3:
		print "Requires two files as arguments!"
	else:
		convertFile(args[1],args[2])

if __name__ == '__main__':
	main(sys.argv)