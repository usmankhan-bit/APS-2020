def checkYear(year): 
    if (( year%400 == 0)or (( year%4 == 0 ) and ( year%100 != 0))):
        return 1
    else:
        return 0

year = int(input())
print(checkYear(year))
