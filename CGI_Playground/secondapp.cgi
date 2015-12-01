import cgi
import cgib, cgib.enable()

print "Content-type: text/html"
print 
print """
<html>
<head><title>Sample CGI Script</title></head>
<body>
  <h3> Sample CGI Script </h3>
"""

form = cgi.FieldStorage()
message = form.getvalue("message","(no message)")

print """
  <p>Previous message: %s</p>
  <p>form
  <form method="post" action="secondapp.cgi">
    <p>message: <input type="text" name="message" value="%d"/></p>
  </form>
</body>
</html>
""" % (message,len(message)+1)
