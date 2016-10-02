function(page) {
    var regex = /src=&quot;([^&]*\/comics\/[^&]*)&quot;/;
    var match = regex.exec(page);
    return match[1];
}
