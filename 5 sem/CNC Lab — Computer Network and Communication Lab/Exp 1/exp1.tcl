set ns [new Simulator]

#open a new file for NAMTRACE
set nf [open out.nam w]
$ns namtrace-all $nf

#open a new file to log TRACE
set tf [open out.tr w]
$ns trace-all $tf

#body of finish procedure
proc finish {} {
    global ns nf tf
    $ns flush-trace
    close $nf
    close $tf
    exec nam out.nam &
    exit 0
}

#Create nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]

#Create links between nodes
$ns duplex-link $n0 $n1 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 1Mb 10ms DropTail

#Set orientation
$ns duplex-link-op $n0 $n1 orient right-up
$ns duplex-link-op $n1 $n2 orient right-down

#Set queue limit - default is 50 packets
$ns queue-limit $n0 $n1 50
$ns queue-limit $n1 $n2 50

#Create transport agent
#Sender
set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0

#receiver
set null0 [new Agent/Null]
$ns attach-agent $n2 $null0
$ns connect $udp0 $null0

#Create Application to generate traffic
set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.005

$cbr0 attach-agent $udp0

#Start and Stop generating traffic
$ns at 0.5 "$cbr0 start"
$ns at 4.5 "$cbr0 stop"

$ns at 5.0 "finish"

$ns run
