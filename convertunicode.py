import unicodedata

def convert_unicode(txt):
    tmp = unicodedata.normalize('NFC',txt)
    return tmp    

to_hop = "Tiếng Việt bão táp"
dung_san = convert_unicode(to_hop)
print(dung_san.encode())
