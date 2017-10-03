function(page) {
    var regex = /data-image="[^"]*\/([^"\/]*).jpg"/;
    var match = regex.exec(page);
    var hash = match[1]

    return "http://is.mediadelivery.fi/img/1920/" + hash + ".jpg";
}
