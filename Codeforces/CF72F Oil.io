input := File standardInput
s := input readLine split
dim := List clone
dim := dim append(s at(0) asNumber)
dim := dim append(s at(1) asNumber)
h := List clone
for (t, 0, 1, 
    s := input readLine split
    list := List clone
    cnt := s removeFirst asNumber
    s foreach (x, list := list append(x asNumber))
    list := list append(0)
    list := list append(dim at(t) + 1)
    list := list sort
    w := 0
    for (i, 0, cnt, if (list at(i) + 1< list at(i+1), w = w + 1))
    h := h append(w)
)
ans := h at(0) * h at(1)
ans println
