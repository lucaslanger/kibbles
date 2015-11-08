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
		with open(input_file) as f:
			for line in f.readlines():
				words = line.translate(None, "()[],.:;\'\"!").split()
				for i in range(len(words)-1):
					pair = (words[i].lower(), words[i+1].lower())
					if pair in word_pairs:
						word_pairs[pair]+=1
					else:
						word_pairs[pair]=1

		for k,v in word_pairs.iteritems():
			print [k[0],k[1]], v

		with open("pairfreq_output.pickle",'wb') as h:
			pickle.dump(word_pairs, h)
	except: 
		print "Something wrong with given file"
