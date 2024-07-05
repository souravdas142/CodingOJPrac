#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<unistd.h>
#include<string.h>
#include<stdbool.h>
#include<dbus-1.0/dbus/dbus.h>

const char *const INTERFACE_NAME="com.sourav.example";
const char *const SERVER_BUS_NAME="com.sourav.example";
const char *const OBJ_PATH_NAME="/com/sourav/adder";
const char *const METHODE_NAME="add_numbers";

DBusError dbus_err;

void print_dbus_error(char *str);

bool isInteger(char *ptr);

int main (int argc,char **argv) {

	DBusConnection *conn;
	int ret;

	dbus_error_init(&dbus_err);
	conn = dbus_bus_get(DBUS_BUS_SESSION,&dbus_err);

	if(dbus_error_is_set(&dbus_err)) {
		print_dbus_error("dbus_bus_get");
	}

	if(!conn)
		exit(1);

	//server request for a human readable well known name
	ret = dbus_bus_request_name(conn,SERVER_BUS_NAME,DBUS_NAME_FLAG_DO_NOT_QUEUE,&dbus_err);

	if(dbus_error_is_set(&dbus_err)) {
		print_dbus_error("dbus_bus_req_name");
	}

	if(ret != DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER) {
		fprintf(stderr, "Dbus: not primary owner, ret = %d\n", ret);
		exit(1);
	}

// handle the server incoming information
	while(true) {
		//Block for msg from the client
		if(!dbus_connection_read_write_dispatch(conn, -1)) {
			fprintf(stderr, "Not connected now.\n");
			exit(1);
		}

		DBusMessage *message;
		if((message=dbus_connection_pop_message(conn)) == NULL) {
			fprintf(stderr, "do not getting message.\n");
			continue;
		}

		if (dbus_message_is_method_call(message,INTERFACE_NAME,METHODE_NAME)) {
			char *s;
			char *str1=NULL, *str2=NULL;
			const char space[4] = "\n\t";
			long i,j;
			bool error = false;

			if (dbus_message_get_args(message,&dbus_err,DBUS_TYPE_STRING,&s, DBUS_TYPE_INVALID)) {
				printf("%s",s);
				//validate recieved message by the client
				str1 = strtok (s, space);
				if(str1)
					str2=strtok(NULL, space);

				if(!str1 || !str2) {
					error=true;
				}
				if(!error) {
					if(isInteger (str1) && isInteger(str2)) {
						i = atol (str1);
						j=atol(str2);
					}
					else
						error=true;
				}

				if (!error) {
					//send reply
					DBusMessage *reply;
					char answer [40];

					sprintf(answer,"sum is %ld", i+j);
					if (( reply= dbus_message_new_method_return (message)) ==NULL ) {
						fprintf(stderr, "error in dbus_message_new_method_return\n");
						exit(1);
					}

					DBusMessageIter iter;
					dbus_message_iter_init_append (reply, &iter);
					char *ptr =  answer;
					if(!dbus_message_iter_append_basic( &iter, DBUS_TYPE_STRING, &ptr)) {
						fprintf(stderr, "error in dbus_message_iter_append_basic\n");
					}

					if (!dbus_connection_send (conn, reply,NULL)) {
						fprintf(stderr, "error in dbus_connection_send\n");
						exit(1);
					}

					dbus_connection_flush (conn);
					dbus_message_unref(reply);

				} else {
					DBusMessage *dbus_error_msg;
					const char error_msg[] = "error in input";
					if((dbus_error_msg = dbus_message_new_error (message, DBUS_ERROR_FAILED, error_msg)) == NULL) {
						fprintf(stderr, "error in dbus_message_new_error \n");
						exit(1);
					}

					if (!dbus_connection_send (conn, dbus_error_msg, NULL)) {
						fprintf(stderr, "error in dbus_connection_send\n");
						exit(1);
					}
					dbus_connection_flush (conn);
					dbus_message_unref(dbus_error_msg);
				}
			}
			else {
				print_dbus_error ("Error getting message\n");
			}
		}
	}
	return 0;
}




void print_dbus_error (char *str)
{
    fprintf (stderr, "%s: %s\n", str, dbus_err.message);
    dbus_error_free (&dbus_err);
}



bool isInteger(char *ptr) {
	while (*ptr && isdigit(*ptr)) {
		ptr++;
	}

	if(ptr!=NULL) return false;

	return true;
}



