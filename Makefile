
all:

docker:
	docker container exec -it cpp_container bash

clean:
	rm -rf **/a.out
	docker container prune
	docker image prune

.PHONY: clean docker
