import sys

know=raw_input()
query=raw_input()

know_value=know.split(';')
know_dict={}
know_set=set()
for i in know_value:
    i_dict={}
    c,v=i.split('_')
    i_dict[c]=v.split('|')
    know_set.add(c)
    know_dict.update(i_dict)

for c in know_dict.keys():
    v_list=know_dict[c]
    v_list_set =know_dict[c]
    for v in v_list:
        if v not in v_list_set:
            query=query.replace(v,' %s/'%v+'%s '%c)
        if v in query:
            query=query.replace(v,' %s/'%v+'%s '%c)
            

print(query)
