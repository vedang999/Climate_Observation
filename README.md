# Climate_Observation
Learning Git

Temperature Analysis System:

A city is divided into ‘n’ no. of different climate stations. Each station has some urban parameters and weather parameters. Urban parameters include
1.	Sky view factor (range from 0.1 to 0.9) 
2.	Vegetation density ratio (%age value)
3.	Population density (Number of people per Sq. km)
4.	Pervious surface fraction (range from 0 to 15)
5.	Impervious surface fraction (range from 0 to 15)
6.	Station status (urban/rural) 
7.	Distance of station to other stations (in km) 
Weather parameters are air temperature, relative humidity recorded for each station every day for one month. 
Write program to provide solution to the  following queries
1.	List the stations with highest heat degree days.
Heat degree days = days on which temperature is higher than average city temperature. Average city temperature is average temperature of all stations on all days.
2.	For any searched station find the thermally comfortable days.
Thermally comfortable days = days for a station on which temperature difference between current station and its nearby rural station (only one i.e. any station can have only one nearest rural station) is minimum. You should calculate thermally comfortable days for urban stations only. Use distance array to find out nearby rural station.
            (P.T.O.)
3.	List dates for all stations with decreasing vegetation density ratio and for which the temperature was more than average city temperature.									            
4.	List the (top ‘k’, k-input) stations with minimum population density with highest maximum temperature. If two stations have same population density, then list those in the order of highest maximum temperature.
5.	Write a function to find the heat island intensity for all urban stations.
Heat island intensity = urban station temp – rural station temp 

Heat island intensity calculation: Identify all the nearby rural station for any urban station and take the average temperature difference for two stations (urban avg. temp-rural avg. temp.).
Note. If two rural stations have same distance metric, then you should consider other metric like pervious surface fraction (higher value to be preferred), to identify the nearby rural station. 

