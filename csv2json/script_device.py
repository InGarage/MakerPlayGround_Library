import json
columnDependencies = [14,15,16,17]   #if you want to add new property field please add index of column to this array(start from zero)
columnArray = [1,4,7]
columnNotArray = [5,6,8,9,10,11,12,13,18,19]
columnProperties = [1,2,3,4]
def newData(header):
    newDataVal = {}
    for ca in columnArray:
        newDataVal[header[ca]]=[]
    for cna in columnNotArray:
        newDataVal[header[cna]]=""
    newDataVal["Dependency"] = []
    newDataVal["Property"] = []
    return newDataVal


def addDependencies(line, header):
    dependencies = {}
    for c in columnDependencies:
        if line[c] != '':
            dependencies[header[c]] = line[c] 
    return dependencies

def addProperties(line, header):
    properties = {}
    for c in columnProperties:
        if line[c] != '':
            properties[header[c]] = line[c] 
    return properties

f = open("device.csv", "r")
output = open("device.json", "w")
text = f.readline()
text = f.readline()
output.write(" [\n")
headers = text.split("\n")
header = headers[0].split(",")
#print header
count = 0
isArray = 0
isDependency = 0
dependency = {}
isProperty = 0
properties = {}
data = newData(header)
#print data
while text != '':

    text = f.readline()
    if text == '':
        break
    #print text
    line = text.split("\n")
    
    line = line[0].split(",")
   
    #print ','
    #add json array
    if line[0]=='':
        
        count = 0
        for col in line:
            isArray=0
            isDependency=0
            isProperty=0
            if col!='':
                for c in columnDependencies:
                    if(count == c):
                        isDependency = 1
                for c in columnProperties:
                    if(count == c):
                        isProperty = 1                      
                if (isDependency == 0)&(isProperty == 0):
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
        dependencies = addDependencies(line, header)
        if dependencies != {}:
            data["Dependency"].append(dependencies)
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
            isDependency=0 
            isProperty=0
            if col!='':
                for c in columnDependencies:
                    if(count == c):
                        isDependency = 1
                for c in columnProperties:
                    if(count == c):
                        isProperty = 1                    
                if (isDependency == 0)&(isProperty == 0):
                    
                    for ca in columnArray :
                        if count==ca :
                            isArray=1
                    
                    if isArray == 1:
                        data[header[count]].append(col)
                    else:
                        data[header[count]] = col
                    
            count = count +1 
        #print line
        dependencies = addDependencies(line,header)
        if(dependencies!={}) :
            data["Dependency"].append(dependencies)
        properties = addProperties(line,header)
        if(properties!={}) :
            data["Property"].append(properties)
              
  
if data!={}:
  
   json.dump(data, output, indent=4, separators=(',', ': '))
       

f.close()
output.write(" ]\n")
output.close()