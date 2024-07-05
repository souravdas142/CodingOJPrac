#!/bin/bash
#



for i in {101..999};do 

	if [[ $i -le 10 ]]; then
		url="https://rms01.realme.net/sw/RMX3471export_11_C.16_202306122024000$i.zip"
	elif [[ $i -le 100 ]]; then
		url="https://rms01.realme.net/sw/RMX3471export_11_C.16_20230612202400$i.zip"
	else
		url="https://rms01.realme.net/sw/RMX3471export_11_C.16_2023061220240$i.zip"

	fi

	if wget --spider $url; then
		echo "file Exist"
		break
	else
		echo "file not exist"
	fi
done
