<?php
/**
 * @file
 * nexteuropa_footer.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function nexteuropa_footer_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-nexteuropa-inst-links_eu-institutions:https://europa.eu/european-union/about-eu/institutions-bodies_en.
  $menu_links['menu-nexteuropa-inst-links_eu-institutions:https://europa.eu/european-union/about-eu/institutions-bodies_en'] = array(
    'menu_name' => 'menu-nexteuropa-inst-links',
    'link_path' => 'https://europa.eu/european-union/about-eu/institutions-bodies_en',
    'router_path' => '',
    'link_title' => 'EU institutions',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'menu-nexteuropa-inst-links_eu-institutions:https://europa.eu/european-union/about-eu/institutions-bodies_en',
      'attributes' => array(
        'data-display-title' => 1,
        'data-hide-children' => 0,
        'data-remove-class' => 0,
      ),
      'item_attributes' => array(
        'data-image' => '',
        'data-display-title' => 1,
        'data-hide-children' => 0,
        'id' => '',
        'class' => '',
        'data-remove-class' => 0,
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-nexteuropa-inst-links_european-union:https://europa.eu/.
  $menu_links['menu-nexteuropa-inst-links_european-union:https://europa.eu/'] = array(
    'menu_name' => 'menu-nexteuropa-inst-links',
    'link_path' => 'https://europa.eu/',
    'router_path' => '',
    'link_title' => 'European Union',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'menu-nexteuropa-inst-links_european-union:https://europa.eu/',
      'attributes' => array(
        'data-display-title' => 1,
        'data-hide-children' => 0,
        'data-remove-class' => 0,
      ),
      'item_attributes' => array(
        'data-image' => '',
        'data-display-title' => 1,
        'data-hide-children' => 0,
        'id' => '',
        'class' => '',
        'data-remove-class' => 0,
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -44,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  
  // Exported menu link: menu-nexteuropa-service-links_about-the-commissions-new-web-presence:https://ec.europa.eu/info/about-commissions-new-web-presence.
  $menu_links['menu-nexteuropa-service-links_about-the-commissions-new-web-presence:https://ec.europa.eu/info/about-commissions-new-web-presence'] = array(
    'menu_name' => 'menu-nexteuropa-service-links',
    'link_path' => 'https://ec.europa.eu/info/about-commissions-new-web-presence',
    'router_path' => '',
    'link_title' => 'About the Commission\'s new web presence',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'data-image' => '',
        'data-display-title' => 1,
        'data-hide-children' => 0,
        'id' => '',
        'class' => '',
        'data-remove-class' => 0,
        'style' => '',
      ),
      'identifier' => 'menu-nexteuropa-service-links_about-the-commissions-new-web-presence:https://ec.europa.eu/info/about-commissions-new-web-presence',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
 
  // Exported menu link: menu-nexteuropa-service-links_contact:https://ec.europa.eu/info/contact_en.
  $menu_links['menu-nexteuropa-service-links_contact:https://ec.europa.eu/info/contact_en'] = array(
    'menu_name' => 'menu-nexteuropa-service-links',
    'link_path' => 'https://ec.europa.eu/info/contact_en',
    'router_path' => '',
    'link_title' => 'Contact',
    'options' => array(
      'title' => 'http://ec.europa.eu/info/contact',
      'alter' => TRUE,
      'identifier' => 'menu-nexteuropa-service-links_contact:https://ec.europa.eu/info/contact_en',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => 21,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Exported menu link: menu-nexteuropa-service-links_cookies:https://ec.europa.eu/info/cookies_en.
  $menu_links['menu-nexteuropa-service-links_cookies:https://ec.europa.eu/info/cookies_en'] = array(
    'menu_name' => 'menu-nexteuropa-service-links',
    'link_path' => 'https://ec.europa.eu/info/cookies_en',
    'router_path' => '',
    'link_title' => 'Cookies',
    'options' => array(
      'attributes' => array(
        'data-display-title' => 1,
        'data-hide-children' => 0,
        'data-remove-class' => 0,
      ),
      'item_attributes' => array(
        'data-image' => '',
        'data-display-title' => 1,
        'data-hide-children' => 0,
        'id' => '',
        'class' => '',
        'data-remove-class' => 0,
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-nexteuropa-service-links_cookies:https://ec.europa.eu/info/cookies_en',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Exported menu link: menu-nexteuropa-service-links_europa-analytics:https://webanalytics.ec.europa.eu.
  $menu_links['menu-nexteuropa-service-links_europa-analytics:https://webanalytics.ec.europa.eu'] = array(
    'menu_name' => 'menu-nexteuropa-service-links',
    'link_path' => 'https://webanalytics.ec.europa.eu',
    'router_path' => '',
    'link_title' => 'Europa Analytics',
    'options' => array(
      'attributes' => array(
        'data-display-title' => 1,
        'data-hide-children' => 0,
        'data-remove-class' => 0,
      ),
      'item_attributes' => array(
        'data-image' => '',
        'data-display-title' => 1,
        'data-hide-children' => 0,
        'id' => '',
        'class' => '',
        'data-remove-class' => 0,
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-nexteuropa-service-links_europa-analytics:https://webanalytics.ec.europa.eu',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => 25,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Exported menu link: menu-nexteuropa-service-links_legal-notice:https://ec.europa.eu/info/legal-notice_en.
  $menu_links['menu-nexteuropa-service-links_legal-notice:https://ec.europa.eu/info/legal-notice_en'] = array(
    'menu_name' => 'menu-nexteuropa-service-links',
    'link_path' => 'https://ec.europa.eu/info/legal-notice_en',
    'router_path' => '',
    'link_title' => 'Legal notice',
    'options' => array(
      'attributes' => array(
        'data-display-title' => 1,
        'data-hide-children' => 0,
        'data-remove-class' => 0,
      ),
      'item_attributes' => array(
        'data-image' => '',
        'data-display-title' => 1,
        'data-hide-children' => 0,
        'id' => '',
        'class' => '',
        'data-remove-class' => 0,
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-nexteuropa-service-links_legal-notice:https://ec.europa.eu/info/legal-notice_en',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -34,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-nexteuropa-service-links_resources-for-partners:http://ec.europa.eu/info/resources-partners_en.
  $menu_links['menu-nexteuropa-service-links_resources-for-partners:http://ec.europa.eu/info/resources-partners_en'] = array(
    'menu_name' => 'menu-nexteuropa-service-links',
    'link_path' => 'http://ec.europa.eu/info/resources-partners_en',
    'router_path' => '',
    'link_title' => 'Resources for partners',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'menu-nexteuropa-service-links_resources-for-partners:http://ec.europa.eu/info/resources-partners_en',
      'menu_token_link_uuid' => '',
      'attributes' => array(
        'data-display-title' => 1,
        'data-hide-children' => 0,
        'data-remove-class' => 0,
      ),
      'item_attributes' => array(
        'data-image' => '',
        'data-display-title' => 1,
        'data-hide-children' => 0,
        'id' => '',
        'class' => '',
        'data-remove-class' => 0,
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Exported menu link: menu-nexteuropa-social-media_facebook:https://www.facebook.com/EuropeanCommission.
  $menu_links['menu-nexteuropa-social-media_facebook:https://www.facebook.com/EuropeanCommission'] = array(
    'menu_name' => 'menu-nexteuropa-social-media',
    'link_path' => 'https://www.facebook.com/EuropeanCommission',
    'router_path' => '',
    'link_title' => 'Facebook',
    'options' => array(
      'identifier' => 'menu-nexteuropa-social-media_facebook:https://www.facebook.com/EuropeanCommission',
      'alter' => TRUE,
      'attributes' => array(
        'data-display-title' => 1,
        'class' => array(
          0 => 'icon',
          1 => 'icon--facebook',
          2 => 'footer__icon--facebook',
          3 => 'footer__icon--social',
        ),
        'data-remove-class' => 0,
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-nexteuropa-social-media_other-social-media:http://ec.europa.eu/dgs/communication/services/journalist/social-media_en.htm.
  $menu_links['menu-nexteuropa-social-media_other-social-media:http://ec.europa.eu/dgs/communication/services/journalist/social-media_en.htm'] = array(
    'menu_name' => 'menu-nexteuropa-social-media',
    'link_path' => 'http://ec.europa.eu/dgs/communication/services/journalist/social-media_en.htm',
    'router_path' => '',
    'link_title' => 'Other social media',
    'options' => array(
      'attributes' => array(
        'data-display-title' => 1,
        'data-remove-class' => 0,
      ),
      'identifier' => 'menu-nexteuropa-social-media_other-social-media:http://ec.europa.eu/dgs/communication/services/journalist/social-media_en.htm',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-nexteuropa-social-media_twitter:https://twitter.com/eu_commission.
  $menu_links['menu-nexteuropa-social-media_twitter:https://twitter.com/eu_commission'] = array(
    'menu_name' => 'menu-nexteuropa-social-media',
    'link_path' => 'https://twitter.com/eu_commission',
    'router_path' => '',
    'link_title' => 'Twitter',
    'options' => array(
      'identifier' => 'menu-nexteuropa-social-media_twitter:https://twitter.com/eu_commission',
      'alter' => TRUE,
      'attributes' => array(
        'data-display-title' => 1,
        'class' => array(
          0 => 'icon',
          1 => 'icon--twitter',
          2 => 'footer__icon--twitter',
          3 => 'footer__icon--social',
        ),
        'data-remove-class' => 0,
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Exported menu link: menu-nexteuropa-social-media_twitter:https://twitter.com/eu_commission.
  $menu_links['menu-nexteuropa-site-links_commissionanditspriorities:https://ec.europa.eu/'] = array(
    'menu_name' => 'menu-nexteuropa-site-links',
    'link_path' => 'https://ec.europa.eu/',
    'router_path' => '',
    'link_title' => 'Commission and it\'s priorities',
    'options' => array(
      'identifier' => 'menu-nexteuropa-site-links_commissionanditspriorities:https://ec.europa.eu/',
      'alter' => TRUE,
      'attributes' => array(
        'data-display-title' => 1,
        'class' => '',
        'data-remove-class' => 0,
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Exported menu link: menu-nexteuropa-site-links_policiesinformationandservices:https://ec.europa.eu/info.
  $menu_links['menu-nexteuropa-site-links_policiesinformationandservices:https://ec.europa.eu/info'] = array(
    'menu_name' => 'menu-nexteuropa-site-links',
    'link_path' => 'https://ec.europa.eu/info',
    'router_path' => '',
    'link_title' => 'Policies, information and services',
    'options' => array(
      'identifier' => 'menu-nexteuropa-site-links_policiesinformationandservices:https://ec.europa.eu/info',
      'alter' => TRUE,
      'attributes' => array(
        'data-display-title' => 1,
        'class' => '',
        'data-remove-class' => 0,
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => 1,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Commission and it\'s priorities');
  t('Commission and it\'s priorities');
  t('About the Commission\'s new web presence');
  t('Advertência jurídica');
  t('Avis juridique');
  t('Aviso jurídico');
  t('Aviz juridic');
  t('Avviż legali');
  t('Contact');
  t('Contacto');
  t('Contatti');
  t('Cookie-k');
  t('Cookie-urile');
  t('Cookies');
  t('Cookies testemunhos de conexão');
  t('ELi institutsioonid');
  t('ES iestādēm');
  t('ES institucijas');
  t('EU institutions');
  t('EU intézményei');
  t('EU-instellingen');
  t('EU-institutionerna');
  t('EU-institutionerne');
  t('EU:n toimielimet');
  t('Europa Analytics');
  t('European Union');
  t('Evästeet');
  t('Eπικοινωνία');
  t('Facebook');
  t('Fianáin');
  t('Fógra dlíthiúil');
  t('Informacja prawna');
  t('Institiúidí an Aontais Eorpaigh');
  t('Institucijama EU-a');
  t('Institucije EU');
  t('Instituciones de la UE');
  t('Instituições da UE');
  t('Institutions de l’UE');
  t('Instituțiile UE');
  t('Instytucje UE');
  t('Istituzioni dell\'UE');
  t('Istituzzjonijiet tal-UE');
  t('Jogi nyilatkozat');
  t('Juridische mededeling');
  t('Juridisk meddelelse');
  t('Juridisks paziņojums');
  t('Kakor ”cookies”');
  t('Kapcsolatfelvétel');
  t('Kolačići');
  t('Kontakt');
  t('Kontaktai');
  t('Kontakti');
  t('Kontaktné údaje');
  t('Kuntatt');
  t('Küpsised');
  t('Legal notice');
  t('Note legali');
  t('Oikeudellinen huomautus');
  t('Orgány EU');
  t('Other social media');
  t('Piškotki');
  t('Pliki cookie');
  t('Pravna obavijest');
  t('Pravno obvestilo');
  t('Právne upozornenie');
  t('Právní upozornění');
  t('Rechtlicher Hinweis');
  t('Resources for partners');
  t('Rättsligt meddelande');
  t('Slapukai');
  t('Súbory cookie');
  t('Sīkdatnes');
  t('Teagmháil');
  t('Teisinė informacija');
  t('Twitter');
  t('Yhteydenotot');
  t('Õigusteave');
  t('Όργανα της ΕΕ');
  t('Ανακοίνωση νομικού περιεχομένου');
  t('Бисквитки');
  t('За контакти');
  t('Правна информация');

  return $menu_links;
}
