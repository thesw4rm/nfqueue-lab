# SYN Packet DEST NAT
iptables -t mangle -I OUTPUT -p tcp --dport 8000 --tcp-flags SYN,RST,ACK,FIN SYN -j NFQUEUE --queue-num 0 --queue-bypass
iptables -t nat -I POSTROUTING -s 10.0.8.4 -p tcp --dport 8000 -j SNAT --to-source 10.10.70.135:8000


#iptables -t mangle -I PREROUTING -p tcp --sport 8000 --tcp-flags SYN,RST,ACK,FIN SYN,ACK -j NFQUEUE --queue-num 0 --queue-bypass # Get SYNACK handshake packet
#iptables -t mangle -A FORWARD -p tcp --dport 8000 --tcp-flags SYN,RST,ACK,FIN SYN -j MARK --set-mark 145

#iptables -t mangle -I FORWARD -p tcp --dport 8000 --tcp-flags SYN,RST,ACK,FIN SYN -j LOG --log-prefix "SYN_PACKET_DETECTED: FORWARD" --log-level 4

#iptables -t mangle -I POSTROUTING -p tcp --dport 8000 --tcp-flags SYN,RST,ACK,FIN SYN -j LOG --log-prefix "SYN_PACKET_DETECTED: POSTROUTING" --log-level 4



