import pickle
import sys
import difflib

arg_count = len(sys.argv)
if arg_count > 2:
	print "Too many arguments. Input arguments should consist of only the file to read from"
elif arg_count < 2:
	print "Missing a filename."
else:
	in_file = sys.argv[1]
	word_pairs = {}
	words = {}
	with open(in_file,"rb") as f:
		word_pairs = pickle.load(f)
		for w in word_pairs:
			words[w[0]] = True
			words[w[1]] = True

	words_k = words.keys()
	while(True):
		s = raw_input()
		word_pair = s.split(" ")
		if len(word_pair) < 1: 
			print "You only entered less than two words. Please enter two words seperated by a space."
		elif len(word_pair) > 2:
			print "No more than two words of input allowed."
		else:
			w0, w1 = word_pair[0], word_pair[1]
			if w0 in words:
				print "Spelling OK!"
			else:
				suggestions = difflib.get_close_matches(w0,words_k,1)
				if len(suggestions) > 0:
					print "Fix:", suggestions[0], w1	
				else:
					print "Detected bad spelling and couldn't find any close suggestions"

