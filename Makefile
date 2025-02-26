all:
	make -C ./Bonus clean
	make -C ./Mandatory

bonus:
	make -C ./Mandatory clean
	make -C ./Bonus

clean:
	make -C ./Mandatory clean
	make -C ./Bonus clean

fclean:
	make -C ./Mandatory fclean
	make -C ./Bonus fclean

re: fclean all

.PHONY: all bonus clean fclean re