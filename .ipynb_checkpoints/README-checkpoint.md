# robotik


# Task 1

Im ersten Task man musste 2 Scripts(Nodes) in Python schreiben (Camera und Processor)
Camera: liest ein zufällige Bild aus dem akutellen Path, dann wandelt es in einem Image-Message(imgmsg) mithilfe von CvBridge:
```
cv2_to_imgmsg(img)
```

Der Camera Node publiziert 2 verschiedene Nachrichten:
1. Dieses Bild an dem Topic "Image"
2. Ein Integer, der das oben gennante Bild entspricht an dem Topic "Int"

Processor: subscribed zu dem Topic "Image" und berarbeitet das Bild mithilfe von cv2-Bibliothek, indem es in einem graustufigen Bild umwandelt und in der Größe anpassen:
```
cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
cv2.resize(gray,(28,28))
```
und dann wieder in Topic "Processed_Image" publizieren.


# Task 2

Bei dem 2. Task ist ein zusätzliche Node für Controller erstellt, es subscribed zu 2 Topics:
1. Topic "Processed_Image" bei dem der Processor das Graustufige Bild publiziert.
2. Topic "Int" bei dem der Camera Messages von Typ "IntwithHeader" publiziert.

Diesen 2 Nachrichten werden anhand von "message_filter" synchronisiert:
```
info_sub = message_filters.Subscriber('Int',IntwithHeader)
pi_sub = message_filters.Subscriber('Processed_Image',Image)
ts = message_filters.TimeSynchronizer([info_sub,pi_sub],10)
ts.registerCallback(callback)
```
In callback werden das Bild und das entsprechende Integer in einer Liste von Tupeln gespeichert.
Ebenso wird ein Service Proxy für den ai_image_processing erstellt, um mit dem Service ai_image_processing von ai-Node zu kommunizieren.

Der Service 'AIService' sendet ein Image an den ai-node und dieser sendet ein Integer zurück.

# Task 3

