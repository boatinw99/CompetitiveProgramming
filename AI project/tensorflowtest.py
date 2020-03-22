import tensorflow as tf
import socket
hello = tf.constant('Hello, ' + socket.gethostname())
sess = tf.Session()
print(sess.run(hello))
