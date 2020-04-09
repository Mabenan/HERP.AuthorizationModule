sap.ui.define([
	"sap/ui/Device",
	"sap/ui/core/mvc/Controller",
	"sap/ui/model/json/JSONModel",
	"sap/m/Popover",
	"sap/m/Button",
	"sap/m/library"
], function (Device, Controller, JSONModel, Popover, Button, library) {
	"use strict";

	return Controller.extend("herp.appframework.auth.controller.Settings", {

		onInit: function () {
			sap.ui.core.UIComponent.getRouterFor(this).getRoute('auth.view.Settings').attachPatternMatched(this._patternMatched, this);
		},

		_patternMatched: function(){
			this.getView().byId("userSettings").bindElement("default>/UserSet(name='"+ this.getOwnerComponent().getModel("session").getProperty("/username")+"')");
		}
	});
});