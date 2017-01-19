import json
columnProperties = [2,4]   #if you want to add new property field please add index of column to this array(start from zero)
columnArray = [3]
columnNotArray = [0,1,5]
def newData(header):
    newDataVal = {}
    for ca in columnArray:
        newDataVal[header[ca]]=[]
    for cna in columnNotArray:
        newDataVal[header[cna]]=""
    newDataVal["Property"] = []
    return newDataVal

def newGroup(name):
    group = {}
    group["children"] = []
    group["name"] = name
    return group

def addProperties(line, header):
    properties = {}
    for c in columnProperties:
        if line[c] != '':
            properties[header[c]] = line[c] 
    return properties

f = open("action.csv", "r")
output = open("action.json", "w")
text = f.readline()
text = f.readline()
output.write(" [\n")
headers = text.split("\n")
header = headers[0].split(",")
#print header
count = 0
isGroup = 0
isProperty = 0
properties = {}
group = newGroup("")
data = newData(header)
while text != '':

    text = f.readline()
    if text == '':
        break
    line = text.split("\n")
    line = line[0].split(",")
    #meet category name
    if (line[0] != '') and (line[1] == ''):
        if (group["children"] != []) & (group["name"] != ""):
            if isGroup != 0:
                output.write(",")
            isGroup = 1
            json.dump(group, output, indent=4, separators=(',', ': '))
        group = newGroup(line[0])
        data = newData(header)

        #print "--------------", line[0], "sdfsfdsf", group
    #add json array
    elif line[0]=='':
        
        count = 0
        for col in line:
            isArray=0
            isProperty=0
            if col!='':
                for c in columnProperties:
                    if(count == c):
                        isProperty = 1                    
                if isProperty == 0:
                    isArray=0
                    for ca in columnArray :
                        if count==ca :
                            isArray=1
                    #print isArray
                    if isArray == 1:
                        data[header[count]].append(col)
                    else:
                        data[header[count]] = col
                    isArray=0
            count = count +1    
    
        #print line  
        properties = addProperties(line, header)
        if properties != {}:
            data["Property"].append(properties) 

    elif line[0]!='' :
        count=0
      
       #normal line  
        if data!= newData(header):
            json.dump(data, output, indent=4, separators=(',', ': '))
            output.write(",")
        #print data["Dependency"]
        
        data = newData(header)
        for col in line:
            isArray=0
            isProperty=0
            if col!='':
                for c in columnProperties:
                    if(count == c):
                        isProperty = 1                    
                if isProperty == 0:
                    
                    for ca in columnArray :
                        if count==ca :
                            isArray=1
                    
                    if isArray == 1:
                        data[header[count]].append(col)
                    else:
                        data[header[count]] = col
                    
            count = count +1   
        #print line
        properties = addProperties(line,header)
        if(properties!={}) :
            data["Property"].append(properties)
              
  
if (group["children"] != []) & (group["name"] != ""):
   output.write(",")
   json.dump(group,output,indent=4,separators=(',', ': '))
       

f.close()
output.write(" ]\n")
output.close()