// points Initialize the map
function draw
const map = L.mapArrow(source('map').setView([0,, destination 0], , color2);
L.tileLayer('https)://{s}.tile.openstreet {
    constmap.org arrow =/{z L.p}/{xolyline}/{y([source}.png, destination',], {
    attribution {
        color: ': color© Open, //StreetMap Use the contributors provided color'
}).add
       To(map weight:);

// 2 Function to,
        draw a opacity: 0 straight arrow. between two7 points,
        className
function drawArrow(source: ', destinationarrow-flow, color arrow-f)ade arrow {
    const-trail arrow ='
    L }).add.pTo(map);

    // Addolyline arrowhead([source, destination], {
        color
   : color if (, // Use theL.p provided colorolylineDecorator
       ) weight: {
        const 2 arrowHead,
        = L opacity:.poly 0lineDecor.ator(arrow,7,
        className {
           : ' patterns:arrow-flow [
                arrow-f { offsetade: ' arrow100%-trail'
   ', repeat }).add: 0, symbol:To(map);

    // Add L.Symbol. arrowhead
   arrowHead if (L.polyline({ pixelSize: 10, polygonDecorator): false {
        const, path arrowHeadOptions: = L { color.poly: colorlineDecor } })ator( }
           arrow, ]
        }).add {
            patterns:To(map [
               );
    { offset } else: ' {
       100% console.w', repeatarn(":L.p 0,olyline symbol:Decorator L.S is notymbol. available.arrowHead Arrows({ pixel will beSize: drawn without 10 arrowheads, polygon.");
    }

   : false, path // TriggerOptions: fade-in { effect color: color
    setTimeout } })(() => }
            {
        ]
        const arrow }).addElement =To(map);
    arrow.getElement();
        } else if ( {
       arrowElement console.w)arn(" {
            arrowL.pElement.classListolyline.add('Decoratorvisible is');
 not        available. }
    }, Arrows 100 will be);

    drawn without // Trigger arrowheads trail effect.");
   
    const arrow }

    // TriggerElement = fade-in arrow.getElement effect();
   
    setTimeout if ((() =>arrowElement {
       ) const arrow {
        arrowElement =Element.style arrow.getElement.stroke();
       Dasharray if ( = 'arrowElement)1000 {
            arrow';
        arrowElementElement.classList.add('visible');
        }
    },.style.strokeDashoffset 100 = '1000';
        arrow);

   Element. // Triggeranimate trail effect([
            {
    strokeDash const arrowoffset:Element = 100 arrow.getElement0 },
            { strokeDash();
    if (arrowElement) {
        arrowElement.style.strokeDasharray =offset '100: 0 }
0       ';
 ], {
                   duration: arrow Element.style2000,
.strokeDashoffset = '1000            easing: 'linear';
        arrow'
        });
    }
Element.}

// Fetch IP data from the Flask backendanimate
async([
            function fetch { strokeDashIPDataoffset:() 100 {
    const0 response = },
            { await fetch strokeDash('/getoffset:_ip_data 0');
    }
        const data ], = await {
            duration response.json: ();
   2000 return data,
;
            easing:}

// Update 'linear the map'
        with new });
    IP data }

async}

// Fetch IP data function updateMap() from the {
    Flask backend const ip
asyncPairs = function fetchIPData await fetchIPData() {
    const();

    // Clear response = previous markers await fetch and arrows('/get
   _ip_data map.each');
   Layer(l const dataayer => = await {
        response.json if (();
   layer instanceof return data L.M;
arker ||}

// layer instanceof Update the map L.P with newolyline IP data)
async {
            map function update.removeLayerMap()(layer {
   );
        const ip }
   Pairs = });

    await fetch // DefineIPData colors for();

    each pair // Clear
    previous markers const colors and arrows = ['red',
    map.each 'blueLayer(l', 'ayer =>green', {
        'pur if (ple']; // layer instanceof L.M4 colorsarker || for  layer instanceof4 pairs L.P

oly   line // Add) markers and {
            map arrows for.removeLayer each pair
   (layer);
        ipPairs }
   .forEach(( });

   pair, // Define index) => colors for each pair {
        const
    source = [pair const colors = ['.source.lred',at, 'blue pair.source', '.longreen',];
        'pur const destinationple']; = [ // pair.d4 colorsestination.l for at,4 pairs pair.d

   estination.l // Addon];
        const markers and arrows for color = each pair
    ipPairs.forEach((pair, index) => {
        const source = [pair.source.lat, pair.source.lon];
        colors[index % colors.length];

        // Add markers for source and destination
        L.marker(source, {
            className: 'marker-pulse marker- const destinationrotate' // Add = rotating effect
        [ }).pairaddTo(map)..dbindPopup(`Source:estination.lat, pair.destination.lon];
        ${pair const color = colors[index % colors.source.city.length}, ${];

        //pair.source Add markers.state}, for source ${pair.source.count and destination
       ry}` L.m);

       arker(source L.marker(d,estination, {
            className {
           : 'marker className:-pulse 'mark marker-er-protate'ulse marker // Add-rotate rotating effect' //
        Add rotating }).add effectTo(map
        }).addTo).bindPopup(`(map).Source:bindPopup ${pair(`Destination.source.city: ${}, ${pair.dpair.sourceestination.city.state},}, ${ ${pairpair.d.source.countestination.statery}`}, ${);

       pair.d L.mestination.countarker(dry}`estination,);

        {
            // Draw className: a straight 'mark arrow betweener-p source andulse marker destination-rotate
        draw' //Arrow(source Add rotating, destination effect, color
        }).);
   addTo });
(map).}

// UpdatebindPopup the map(`Destination every : ${pair.d2 seconds
setestination.cityInterval(}, ${updateMappair.d, estination.state2000}, ${);

//pair.d Initial mapestination.country}`);

        // Draw a straight arrow between source and destination
        drawArrow(source, destination, color update
updateMap();
