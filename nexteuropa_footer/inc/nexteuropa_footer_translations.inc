<?php
/**
 * @file
 * Code for the Nexteuropa footer feature.
 */

/**
 * Helper function to get the mlid basing on the link name.
 */
function _nexteuropa_footer_translations() {
  $items = [];

  $items['menu-nexteuropa-social-media']['title'] = [
    'title' => t('Follow the European Commission'),
    'weight' => '0',
    'languages' => [
      'bg' => 'Следвайте Европейската комисия',
      'cs' => 'Sledujte Evropskou komisi',
      'da' => 'Følg Europa-Kommissionen',
      'de' => 'Folgen Sie der Europäischen Kommission',
      'et' => 'Jälgige Euroopa Komisjoni',
      'el' => 'Ακολουθήστε την Ευρωπαϊκή Επιτροπή',
      'es' => 'Seguir a la Comisión Europea',
      'fi' => 'Seuraa Euroopan komissiota',
      'fr' => 'Suivre la Commission européenne',
      'ga' => 'An Coimisiún Eorpach a leanúint',
      'hr' => 'Pratite Europsku komisiju',
      'hu' => 'Kövessen bennünket!',
      'it' => 'Segui la Commissione europea',
      'lt' => 'Sekite Europos Komisijos naujienas',
      'lv' => 'Sekojiet Eiropas Komisijai',
      'mt' => 'Segwi l-Kummissjoni Ewropea',
      'nl' => 'Volg de Europese Commissie',
      'pl' => 'Komisja Europejska w mediach społecznościowych',
      'pt-pt' => 'Siga a Comissão Europeia',
      'ro' => 'Urmăriți Comisia Europeană',
      'sk' => 'Sledujte Európsku komisiu',
      'sl' => 'Spremljajte Evropsko komisijo',
      'sv' => 'Följ kommissionen',
    ],
  ];

  $items['menu-nexteuropa-social-media']['items'][] = [
    'title' => t('Other social media'),
    'weight' => '0',
    'languages' => [
      'bg' => 'Други социални мрежи',
      'cs' => 'Ostatní sociální sítě',
      'da' => 'Andre sociale netværk',
      'de' => 'Andere soziale Medien',
      'et' => 'Muud sotsiaalvõrgustikud',
      'el' => 'Άλλα μέσα κοινωνικής δικτύωσης',
      'es' => 'Otras redes sociales',
      'fi' => 'Muut yhteisöpalvelut',
      'fr' => 'Autres réseaux sociaux',
      'ga' => 'Líonraí sóisialta eile',
      'hr' => 'Ostale društvene mreže',
      'hu' => 'Egyéb közösségi hálózatok',
      'it' => 'Altri social network',
      'lv' => 'Citi sociālie tīkli',
      'lt' => 'Kiti socialiniai tinklai',
      'mt' => 'Netwerks soċjali oħrajn',
      'nl' => 'Overige sociale netwerken',
      'pl' => 'Inne serwisy społecznościowe',
      'pt-pt' => 'Outras redes sociais',
      'ro' => 'Alte rețele sociale',
      'sk' => 'Iné sociálne siete',
      'sl' => 'Druga družbena omrežja',
      'sv' => 'Andra sociala medier',
    ],
  ];

  $items['menu-nexteuropa-service-links']['items'][] = [
    'title' => t("About the Commission's new web presence"),
    'weight' => '0',
    'languages' => [
      'bg' => 'За новото присъствие на Комисията в интернет',
      'cs' => 'Ostatní sociální sítě',
      'da' => 'Om Kommissionens nye website',
      'de' => 'Über den neuen Internetauftritt der Kommission',
      'et' => 'Komisjoni uue veebikeskkonna tutvustus',
      'el' => '',
      'es' => 'Sobre la nueva página web de la Comisión',
      'fi' => 'Tietoa komission verkkosivujen uudistuksesta',
      'fr' => 'À propos de la nouvelle présence de la Commission sur le web',
      'ga' => 'Eolas faoi láithreacht nua an Choimisiúin Eorpaigh ar an idirlíon',
      'hr' => 'O novim internetskim stranicama Komisije',
      'hu' => 'A Bizottság új webes jelenléte',
      'it' => 'La nuova presenza online della Commissione',
      'lv' => 'Par Komisijas jauno tīmekļa vietni',
      'lt' => 'Apie naują Komisijos interneto svetainę',
      'mt' => 'Dwar il-preżenza l-ġdida tal-Kummissjoni fuq il-web',
      'nl' => 'Over de nieuwe website van de Europese Commissie',
      'pl' => 'Informacje o nowej generacji stron internetowych Komisji',
      'pt-pt' => 'Sobre a nova presença da Comissão na Web',
      'ro' => 'Despre noul portal al Comisiei',
      'sk' => 'Nová prezentácia Komisie na internete',
      'sl' => 'O novi spletni prisotnosti Evropske komisije',
      'sv' => 'Om kommissionens nya webbplats',
    ],
  ];

  $items['menu-nexteuropa-service-links']['items'][] = [
    'title' => t('Resources for partners'),
    'weight' => '1',
    'languages' => [],
  ];

  $items['menu-nexteuropa-service-links']['items'][] = [
    'title' => t('Cookies'),
    'weight' => '2',
    'languages' => [
      'bg' => 'Бисквитки',
      'cs' => 'Cookies',
      'da' => 'Cookies',
      'de' => 'Cookies',
      'et' => 'Küpsised',
      'el' => 'Cookies',
      'es' => 'Cookies',
      'fi' => 'Evästeet',
      'fr' => 'Cookies',
      'ga' => 'Fianáin',
      'hr' => 'Kolačići',
      'hu' => 'Cookie-k',
      'it' => 'Cookies',
      'lv' => 'Sīkdatnes',
      'lt' => 'Slapukai',
      'mt' => 'Cookies',
      'nl' => 'Cookies',
      'pl' => 'Pliki cookie',
      'pt-pt' => 'Cookies testemunhos de conexãob',
      'ro' => 'Cookie-urile',
      'sk' => 'Súbory cookie',
      'sl' => 'Piškotki',
      'sv' => 'Kakor ”cookies',
    ],
  ];

  $items['menu-nexteuropa-service-links']['items'][] = [
    'title' => t('Legal notice'),
    'weight' => '3',
    'languages' => [
      'bg' => 'Правна информация',
      'cs' => 'Právní upozornění',
      'da' => 'Juridisk meddelelse',
      'de' => 'Rechtlicher Hinweis',
      'et' => 'Õigusteave',
      'el' => 'Ανακοίνωση νομικού περιεχομένου',
      'es' => 'Aviso jurídico',
      'fi' => 'Oikeudellinen huomautus',
      'fr' => 'Avis juridique',
      'ga' => 'Fógra dlíthiúil',
      'hr' => 'Kolačići',
      'hu' => 'Jogi nyilatkozat',
      'it' => 'Note legali',
      'lv' => 'Juridisks paziņojums',
      'lt' => 'Teisinė informacija',
      'mt' => 'Avviż legali',
      'nl' => 'Juridische mededeling',
      'pl' => 'Informacja prawna',
      'pt-pt' => 'Advertência jurídica',
      'ro' => 'Aviz juridic',
      'sk' => 'Právne upozornenie',
      'sl' => 'Pravno obvestilo',
      'sv' => 'Rättsligt meddelande',
    ],
  ];

  $items['menu-nexteuropa-service-links']['items'][] = [
    'title' => t('Contact'),
    'weight' => '4',
    'languages' => [
      'bg' => 'За контакти',
      'cs' => 'Kontakt',
      'da' => 'Kontakt',
      'de' => 'Kontakt',
      'et' => 'Kontakt',
      'el' => 'Επικοινωνία',
      'es' => 'Contacto',
      'fi' => 'Yhteydenotot',
      'fr' => 'Contact',
      'ga' => 'Teagmháil',
      'hr' => 'Kontakt',
      'hu' => 'Kapcsolatfelvétel',
      'it' => 'Contatti',
      'lv' => 'Kontakti',
      'lt' => 'Kontaktai',
      'mt' => 'Kuntatt',
      'nl' => 'Contact',
      'pl' => 'Kontakt',
      'pt-pt' => 'Contacto',
      'ro' => 'Contact',
      'sk' => 'Kontaktné údaje',
      'sl' => 'Kontakt',
      'sv' => 'Kontakt',
    ],
  ];

  $items['menu-nexteuropa-site-links']['title'] = [
    'title' => t('European Commission'),
    'languages' => [
      'bg' => 'Европейска комисия',
      'cs' => 'Evropská komise',
      'da' => 'Europa-Kommissionen',
      'de' => 'Europäische Kommission',
      'et' => 'Euroopa Komisjon',
      'el' => 'Ευρωπαϊκή Επιτροπή',
      'es' => 'Comisión Europea',
      'fi' => 'Euroopan komissio',
      'fr' => 'Commission européenne',
      'ga' => 'An Coimisiún Eorpach',
      'hr' => 'Europska komisija',
      'hu' => 'Európai Bizottság',
      'it' => 'Commissione europea',
      'lv' => 'Eiropas Komisija',
      'lt' => 'Europos Komisija',
      'mt' => 'Il-Kummissjoni Ewropea',
      'nl' => 'Europese Commissie',
      'pl' => 'Komisja Europejska',
      'pt-pt' => 'Comissão Europeia',
      'ro' => 'Comisia Europeană',
      'sk' => 'Európska komisia',
      'sl' => 'Evropska komisija',
      'sv' => 'Europeiska kommissionen',
    ],
  ];

  $items['menu-nexteuropa-site-links']['items'][] = [
    'title' => t("Commission and its priorities"),
    'weight' => '0',
    'languages' => [
      'bg' => 'Комисията и нейните приоритети',
      'cs' => 'Komise a její priority',
      'da' => 'Kommissionen og dens prioriteter',
      'de' => 'Prioritäten der Kommission',
      'et' => 'Komisjon ja tema prioriteedid',
      'el' => 'Η Ευρωπαϊκή Επιτροπή και οι προτεραιότητές της',
      'es' => 'La Comisión y sus prioridades',
      'fi' => 'Komissio ja sen toiminnan painopisteet',
      'fr' => 'La Commission et ses priorités',
      'ga' => 'An Coimisiún agus a thosaíochtaí',
      'hr' => 'Prioriteti Komisije',
      'hu' => 'A Bizottság és prioritásai',
      'it' => 'Le priorità della Commissione',
      'lv' => 'Komisija un tās prioritātes',
      'lt' => 'Komisija ir jos prioritetai',
      'mt' => 'Il-Kummissjoni u l-prijoritajiet tagħha',
      'nl' => 'Commissarissen en prioriteiten',
      'pl' => 'Komisja i jej priorytety',
      'pt-pt' => 'As prioridades da Comissão',
      'ro' => 'Comisia și prioritățile sale',
      'sk' => 'Komisia a jej priority',
      'sl' => 'Komisija in njene prednostne naloge',
      'sv' => 'Kommissionen och dess prioriteringar',
    ],
  ];

  $items['menu-nexteuropa-site-links']['items'][] = [
    'title' => t('Policies, information and services'),
    'weight' => '1',
    'languages' => [
      'bg' => 'Политики, информация и услуги',
      'cs' => 'Oblasti politiky, informace a služby',
      'da' => 'Politikker, oplysninger og tjenester',
      'de' => 'Politikfelder, Informationen und Dienste',
      'et' => 'Poliitikavaldkonnad, teave ja teenused',
      'el' => 'Πολιτικές, πληροφορίες και υπηρεσίες',
      'es' => 'Políticas, información y servicios',
      'fi' => 'Politiikan alat, palvelut, tietolähteet',
      'fr' => 'Politiques, informations et services',
      'ga' => 'Beartais, eolas agus seirbhísí',
      'hr' => 'Politike, informacije i službe',
      'hu' => 'Szakpolitikák, információk és szolgálatok',
      'it' => 'Politiche, informazioni e servizi',
      'lv' => 'Politikas jomas, informācija un dienesti',
      'lt' => 'Politika, informacija ir paslaugos',
      'mt' => 'Politiki, informazzjoni u servizzi',
      'nl' => 'Beleid, informatie en diensten',
      'pl' => 'Obszary polityki, informacje i usługi',
      'pt-pt' => 'Políticas, informações e serviços',
      'ro' => 'Informații și domenii de interes',
      'sk' => 'Politiky, informácie a služby',
      'sl' => 'Politike, informacije in službe',
      'sv' => 'Politikområden, information och tjänster',
    ],
  ];

  $items['menu-nexteuropa-inst-links']['title'] = [
    'title' => t('European Union'),
    'languages' => [
      'bg' => 'Европейски съюз',
      'cs' => 'Evropská unie',
      'da' => 'Europæiske Unions',
      'de' => 'Europäische Union',
      'et' => 'Euroopa Liit',
      'el' => 'Ευρωπαϊκή Ένωση',
      'es' => 'Unión Europea',
      'fi' => 'Euroopan unioni',
      'fr' => 'Union européenne',
      'ga' => 'Aontais Eorpaigh',
      'hr' => 'Europske unije',
      'hu' => 'Európai Unió',
      'it' => 'Unione europea',
      'lv' => 'Eiropas Savienība',
      'lt' => 'Europos Sąjunga',
      'mt' => 'L-Unjoni Ewropea',
      'nl' => 'Europese Unie',
      'pl' => 'Unia Europejska',
      'pt-pt' => 'União Europeia',
      'ro' => 'Uniunea Europeană ',
      'sk' => 'Európska únia',
      'sl' => 'Evropska unija',
      'sv' => 'Europeiska unionen',
    ],
  ];

  $items['menu-nexteuropa-inst-links']['items'][] = [
    'title' => t('European Union'),
    'weight' => '0',
    'languages' => [
      'bg' => 'Европейски съюз',
      'cs' => 'Evropská unie',
      'da' => 'Europæiske Unions',
      'de' => 'Europäische Union',
      'et' => 'Euroopa Liit',
      'el' => 'Ευρωπαϊκή Ένωση',
      'es' => 'Unión Europea',
      'fi' => 'Euroopan unioni',
      'fr' => 'Union européenne',
      'ga' => 'Aontais Eorpaigh',
      'hr' => 'Europske unije',
      'hu' => 'Európai Unió',
      'it' => 'Unione europea',
      'lv' => 'Eiropas Savienība',
      'lt' => 'Europos Sąjunga',
      'mt' => 'L-Unjoni Ewropea',
      'nl' => 'Europese Unie',
      'pl' => 'Unia Europejska',
      'pt-pt' => 'União Europeia',
      'ro' => 'Uniunea Europeană ',
      'sk' => 'Európska únia',
      'sl' => 'Evropska unija',
      'sv' => 'Europeiska unionen',
    ],
  ];

  $items['menu-nexteuropa-inst-links']['items'][] = [
    'title' => t('EU Institutions'),
    'weight' => '1',
    'languages' => [
      'bg' => 'Институции на ЕС',
      'cs' => 'Orgány EU',
      'da' => 'EU-institutionerne',
      'de' => 'EU-Institutionen',
      'et' => 'ELi institutsioonid',
      'el' => 'Όργανα της ΕΕ',
      'es' => 'Instituciones de la UE',
      'fi' => 'EU:n toimielimeti',
      'fr' => 'Institutions de l’UE',
      'ga' => 'Institiúidí an Aontais Eorpaigh',
      'hr' => 'Institucijama EU-a',
      'hu' => 'EU intézményei',
      'it' => 'Istituzioni dell\'UE',
      'lv' => 'ES iestādēm',
      'lt' => 'ES institucijоs',
      'mt' => 'Istituzzjonijiet tal-UE',
      'nl' => 'EU-instellingen',
      'pl' => 'Instytucje UE',
      'pt-pt' => 'Instituições da UE',
      'ro' => 'Instituțiile UE',
      'sk' => 'Inštitúcie EÚ',
      'sl' => 'Institucije EU',
      'sv' => 'EU-institutionerna',
    ],
  ];

  return $items;
}
