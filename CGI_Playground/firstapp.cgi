import cgi

def main():
    print "Content-type: text/html\n"
    form = cgi.FieldStorage() 
    if form.has_key("user") and form["user"] != "":
        print "<h1>Hello", form["user"].value, "</h1>"
    else:
        print "<h1>Error! Please enter your name.</h1>"
        return

    if form.has_key("graduating"):
        print "<h2>Please pickup your cap and gown.</h2>"

main()
