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
		for wp in word_pairs:
			w_e = eval(wp)
			words[w_e[0]] = True

	def pair_count(k):
		if k in word_pairs:
			return word_pairs[k]
		else:
			return 0

	#print word_pairs.keys()

	while(True):
		s = raw_input()
		word_pair = s.split(" ")
		if len(word_pair) < 1 or len(word_pair) > 2: 
			print "Error: incorrect input format"
		else:
			w0, w1 = word_pair[0].lower(), word_pair[1].lower()
			if w0 in words:
				print "Spelling OK!"
			else:
				suggestions = difflib.get_close_matches(w0,words.keys(),10)
				if len(suggestions) > 0:
					best_suggestion = max(suggestions,key=lambda x: pair_count(str([x,w1])) )
					print "Fix:", best_suggestion, w1 #, pair_count(str([best_suggestion,w1]))
				else:
					print "Detected bad spelling but couldn't find any close suggestions"

