# This script is used to generate the table on README.md
# Needs to be run from the parent directory, and outputs the table 
# in md format to 'table.out'
import os
import re


SEP = '| '
HEADER_SEP = ' :--------: '

HEADER_LINE = SEP + 'Topic Name' + SEP + '# of Problems' + SEP
HEADER_BOLD = SEP + HEADER_SEP + SEP + HEADER_SEP + SEP
BASE_TOPIC_LINK = 'https://github.com/norubai/interviewbit-problems/tree/master/' 


def get_subdirs():
	cmd = 'ls -d */'
	dir_list_str = os.popen(cmd).read().strip()
	return [x[:-1] for x in dir_list_str.splitlines()]

def get_number_of_problems(subdir):
	subdir = re.sub(' ', '\ ', subdir)
	cmd = 'ls ' + subdir + ' | wc -w'
	return os.popen(cmd).read().strip()

def topic_link(topic_name):
	topic_name = re.sub(' ', '%20', topic_name)
	return BASE_TOPIC_LINK + topic_name	


#get_number_of_problems('Stacks And Queues')
dir_list = get_subdirs()
#print(dir_list)

with open('table.out', 'w') as out:
	out.write(HEADER_LINE); out.write('\n')
	out.write(HEADER_BOLD);  out.write('\n')
	for dir in dir_list:
		# fi and se for first column & second column
		fi = '['+dir+'](' + topic_link(dir) + ')' 
		se = get_number_of_problems(dir)
		print('{:<25}# of problems: {}'.format(dir, se))
		line = SEP + fi + SEP + se + SEP
		out.write(line); 	out.write('\n')
