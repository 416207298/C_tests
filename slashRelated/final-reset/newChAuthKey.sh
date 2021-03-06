#!/bin/bash

# $1--user, $2--IP, $3--old_key_timeStamp, $4--new_key_timeStamp, $5---SPVIp,	$6--rootPwd                                                      
if [ $# -ne 6 ]; then                                                                                          
    echo "Six arguments are needed." 
    echo "1. username   2. IP   3. old_key_timeStamp  4. new_key_timeStamp  5.SPVIp   6.rootPwd"  
    exit                                                                                                                      
else 
	expect <<- EOF
	spawn ssh root@$2
	expect {
		"*(yes/no)?*" { send "yes\r";exp_continue }
		"password" { send "$6\r" }
	 }
	expect "*]*"
	set timeout 5
	send "su $1\r"   

	expect "*]*"
	send "cd ~/.ssh/\r"
	expect "*]*"
	send "scp root@$5:/root/.ssh/id_rsa$4.pub .\r"
	expect {
		"*(yes/no)?*" { send -- "yes\r";exp_continue }
		"*password*" { send -- " \r" }
	}
	expect "*]*"
	send -- "cat id_rsa$4.pub >> authorized_keys\r"
	expect "*]*"
	send "chmod 600 authorized_keys\r"
	expect "*]*"
	send "echo authorized done.\r"
	expect "done."
	send "exit\r"
	expect "*]*"
	send "exit\r"
	expect eof
	EOF

/root/codes/final-reset/Newclean.sh $3 $1 $2 $4 $5 $6
fi

