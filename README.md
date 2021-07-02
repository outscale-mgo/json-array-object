# json-array-object
small utilitaire to create json array and object in c89


```
✦ ❯ json-object k0 v0 k1 v1
{"k0":"v0","k1":"v1"}
✦ ❯ json-array v1 v2 v3
["v1","v2","v3"]
✦ ❯ json-object k0 v0 k1 v1 k2 $(json-array v10 v20 v30)
{"k0":"v0","k1":"v1","k2":["v10","v20","v30"]}
```
