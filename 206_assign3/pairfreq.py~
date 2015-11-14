import sys
import pickle

arg_count = len(sys.argv)

if arg_count > 2:
	print "Too many arguments. Input arguments should consist of only the file to read from"
elif arg_count < 2:
	print "Missing a filename."
else:
	try:
		word_pairs = {}
		input_file = sys.argv[1]
	
		def ignore_punctuation(s):
			punctuation = "()[],.:;\'\"!"
			for p in punctuation:
				s = s.replace(p," ")
			return s
				

		with open(input_file) as f:
			for line in f.readlines():
				words = ignore_punctuation(line).split()
				for i in range(len(words)-1):
					str_pair = str([words[i].lower(), words[i+1].lower()])
					if str_pair in word_pairs:
						word_pairs[str_pair]+=1
					else:
						word_pairs[str_pair]=1

		for k,v in word_pairs.iteritems():
			print k, v

		out_file = input_file.split(".txt")[0] + ".pickle"
		with open(out_file,'wb') as h:
			pickle.dump(word_pairs, h)
	except: 
		print "Something wrong with given file"
