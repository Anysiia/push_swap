# push_swap

How to create a list of random number using bash:
`LIST=$(seq -1000 1000 | shuf -n 100 | xargs)`

To test this project:
`LIST=$(seq -1000 1000 | shuf -n 100 | xargs); ./push_swap $LIST | ./checker $LIST ; ./push_swap $LIST | wc -l `
