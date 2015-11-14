import sys

arg_count = len(sys.argv)


if arg_count > 2:
	print "Too many arguments. Input arguments should consist of only the file to read from"
elif arg_count < 2:
	print "Missing a filename."
else:
	try:
		word_counts = {}
		def ignore_punctuation(s):
			punctuation = "()[],.:;\'\"!"
			for p in punctuation:
				s = s.replace(p," ")
			return s
				
		input_file = sys.argv[1]
		with open(input_file) as f:
			for line in f.readlines():
				words = ignore_punctuation(line).split()
				for w in words:
					lower_w = w.lower()
					if lower_w in word_counts:
						word_counts[lower_w]+=1
					else:
						word_counts[lower_w]=1
	
		for k,v in word_counts.iteritems():
			print k, v
	except:
		print "Something wrong with given file"
