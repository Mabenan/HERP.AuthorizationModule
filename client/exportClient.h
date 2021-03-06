/*
 * export.h
 *
 *  Created on: 29.02.2020
 *      Author: doene
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_EXPORT_H_
#define REPS_HERP_AUTHORIZATIONMODULE_EXPORT_H_


#ifdef _BUILDING_HERP_AUTHORIZATION_MODULE
#define HERP_AUTHORIZATION_MODULE_DLL_EXPORT QX_DLL_EXPORT_HELPER
#else // _BUILDING_HERP_AUTHORIZATION_MODULE
#define HERP_AUTHORIZATION_MODULE_DLL_EXPORT QX_DLL_IMPORT_HELPER
#endif // _BUILDING_HERP_AUTHORIZATION_MODULE

#ifdef _BUILDING_HERP_AUTHORIZATION_MODULE
#define HERP_REGISTER_HPP_HERP_AUTHORIZATION_MODULE QX_REGISTER_HPP_EXPORT_DLL
#define HERP_REGISTER_CPP_HERP_AUTHORIZATION_MODULE QX_REGISTER_CPP_EXPORT_DLL
#define HERP_REGISTER_COMPLEX_HPP_HERP_AUTHORIZATION_MODULE QX_REGISTER_COMPLEX_CLASS_NAME_HPP_EXPORT_DLL
#define HERP_REGISTER_COMPLEX_CPP_HERP_AUTHORIZATION_MODULE QX_REGISTER_COMPLEX_CLASS_NAME_CPP_EXPORT_DLL
#else // _BUILDING_HERP_AUTHORIZATION_MODULE
#define HERP_REGISTER_HPP_HERP_AUTHORIZATION_MODULE QX_REGISTER_HPP_IMPORT_DLL
#define HERP_REGISTER_CPP_HERP_AUTHORIZATION_MODULE QX_REGISTER_CPP_IMPORT_DLL
#define HERP_REGISTER_COMPLEX_HPP_HERP_AUTHORIZATION_MODULE QX_REGISTER_COMPLEX_CLASS_NAME_HPP_IMPORT_DLL
#define HERP_REGISTER_COMPLEX_CPP_HERP_AUTHORIZATION_MODULE QX_REGISTER_COMPLEX_CLASS_NAME_CPP_IMPORT_DLL
#endif // _BUILDING_HERP_AUTHORIZATION_MODULE


#endif /* REPS_HERP_AUTHORIZATIONMODULE_EXPORT_H_ */
