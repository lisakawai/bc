#include "addressbook-impl.h"
#include <vector>

using namespace std;

bool MyAddressBook::Insert(const Contact& contact_new){
	for (const auto &contact : contacts_){
		if (contact.email() == contact_new.email() || contact.name() == contact_new.name()){
			return false;
		}
	}
	contacts_.push_back(contact_new);
	for (const auto &contact : contacts_){
		if (contact.email() == contact_new.email() && contact.name() == contact_new.name()){
			return true;
		}
	}
	return false;
}


const Contact* MyAddressBook::FindEmail(const string &email) const {
	for (const auto &contact : contacts_){
		if (contact.email() == email){
			return &contact;
		}	
	}
	return nullptr;
}

const Contact* MyAddressBook::FindName(const string &name) const {
	for (const auto &contact : contacts_){
		if (contact.name() == name){
			return &contact;
		}
	}
	return nullptr;
}

const Contact* MyAddressBook::FindNext(const Contact& contact_cur) const {
	int index = 0;
	for (const auto &contact : contacts_){
		if (contact.name() == contact_cur.name()){
			if (index + 1 == contacts_.size()){
				return nullptr;
			}
			return &contact + 1;
		}
		index++;
	}
	return nullptr;
}

bool MyAddressBook::Delete(const Contact& contact_del) {
	int index = 0;
	for (const auto &contact : contacts_){
		if (contact.name() == contact_del.name()){
			contacts_.erase(contacts_.begin() + index);
			return true;
		}
		index += 1;
	}
	return false;
}




