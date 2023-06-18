import pandas as pd

data = pd.read_csv("ForestRoad PV 3kwp.csv", sep=";")

# d = pd.to_datetime(data["datetime"], format="mixed")
# print(d)
# print(d[0])
# print(d[len(d)-1])
# with open("a.txt", 'a+') as a:
#     a.writelines([str(d[0]), '\n', str(d[len(d)-1])])

# print(data)


def replace():
    for i in range(len(data["P_GEN_MAX"])):
        if data.at[i, "P_GEN_MAX"] == 0.002:
            data.at[i, "P_GEN_MAX"] = 0
        if data.at[i, "P_GEN_MIN"] == 0.002:
            data.at[i, "P_GEN_MIN"] = 0


replace()
for i in range(len(data["P_GEN_MAX"])):
    data.at[i, "P_GEN"] = (data.at[i, "P_GEN_MIN"]+data.at[i, "P_GEN_MAX"])/2
# print(data)


def find_max(day):
    day = pd.to_datetime(day, dayfirst=True).normalize()
    max = 0
    for i in range(len(data["P_GEN_MAX"])):
        if pd.to_datetime(data.at[i, "datetime"], dayfirst=True).normalize() == day:
            if data.at[i, "P_GEN_MAX"] > max:
                max = data.at[i, "P_GEN_MAX"]

    return max


def find_av(day):
    day = pd.to_datetime(day, dayfirst=True).normalize()
    tt = 0
    n = 0
    for i in range(len(data["P_GEN_MAX"])):
        if pd.to_datetime(data.at[i, "datetime"], dayfirst=True).normalize() == day:
            n += 1
            tt += data.at[i, "P_GEN_MAX"]

    return tt/n


print(find_max("01/10/2013"))
print(find_av("01/10/2013"))
data.to_csv('Cleaned-ForestRoad PV 3kwp.csv', sep=";")
