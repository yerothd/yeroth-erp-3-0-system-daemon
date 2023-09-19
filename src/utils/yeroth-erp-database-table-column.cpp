/*
 * yeroth-erp-database-table-column.cpp
 *
 *      Author: PROF. DR.-ING. DIPL.-INF. Xavier Noumbissi Noundou
 */

#include "yeroth-erp-database-table-column.hpp"


const QString YerothDatabaseTableColumn::IS_SERVICE("is_service");
const QString YerothDatabaseTableColumn::IS_VENTE_EN_GROS("is_vente_en_gros");
const QString YerothDatabaseTableColumn::ID_ALERTE("id_alerte");
const QString YerothDatabaseTableColumn::ID("id");
const QString YerothDatabaseTableColumn::HISTORIQUE_STOCK("historique_stock");
const QString YerothDatabaseTableColumn::CLIENTS_ID("clients_id");
const QString
YerothDatabaseTableColumn::
REFERENCE_RECU_PAIEMENT_CLIENT("reference_recu_paiement_client");
const QString YerothDatabaseTableColumn::REFERENCE_RECU_VENDU("reference_recu_vendu");
const QString YerothDatabaseTableColumn::REFERENCE_RECU_SORTIE("reference_recu_sortie");
const QString YerothDatabaseTableColumn::ENREGISTREUR_STOCK("enregistreur_stock");
const QString YerothDatabaseTableColumn::REFERENCE("reference");
const QString YerothDatabaseTableColumn::COMPTE_FOURNISSEUR("compte_fournisseur");
const QString YerothDatabaseTableColumn::COMPTE_CLIENT("compte_client");
const QString
YerothDatabaseTableColumn::
DETTE_MAXIMALE_COMPTE_CLIENT("dette_maximale_compte_client");
const QString YerothDatabaseTableColumn::CATEGORIE("categorie");
const QString YerothDatabaseTableColumn::QUANTITE("quantite");
const QString YerothDatabaseTableColumn::STOCK_DALERTE("stock_dalerte");
const QString YerothDatabaseTableColumn::STOCK_MINIMUM("stock_minimum");
const QString YerothDatabaseTableColumn::STOCK_MAXIMUM("stock_maximum");
const QString YerothDatabaseTableColumn::QUANTITE_VENDUE("quantite_vendue");
const QString YerothDatabaseTableColumn::QUANTITE_TOTALE("quantite_totale");
const QString YerothDatabaseTableColumn::QUANTITE_SORTIE("quantite_sortie");
const QString
YerothDatabaseTableColumn::
DESCRIPTION_FOURNISSEUR("description_fournisseur");
const QString YerothDatabaseTableColumn::DESCRIPTION_PRODUIT("description_produit");
const QString YerothDatabaseTableColumn::PRIX_UNITAIRE("prix_unitaire");
const QString YerothDatabaseTableColumn::PRIX_UNITAIRE_EN_GROS("prix_unitaire_en_gros");
const QString YerothDatabaseTableColumn::REFERENCE_RECU_DACHAT("reference_recu_dachat");
const QString YerothDatabaseTableColumn::PRIX_DACHAT_PRECEDENT("prix_dachat_precedent");
const QString YerothDatabaseTableColumn::PRIX_DACHAT("prix_dachat");
const QString YerothDatabaseTableColumn::PRIX_VENTE_PRECEDENT("prix_vente_precedent");
const QString
YerothDatabaseTableColumn::
PRIX_VENTE_EN_GROS_PRECEDENT("prix_vente_en_gros_precedent");
const QString YerothDatabaseTableColumn::PRIX_VENTE("prix_vente");
const QString YerothDatabaseTableColumn::PRIX_VENTE_EN_GROS("prix_vente_en_gros");
const QString
YerothDatabaseTableColumn::
REFERENCE_DU_COMPTE_BANCAIRE("reference_du_compte_bancaire");
const QString
YerothDatabaseTableColumn::
AGENCE_DU_COMPTE_BANCAIRE("agence_du_compte_bancaire");
const QString
YerothDatabaseTableColumn::
INTITULE_DU_COMPTE_BANCAIRE("intitule_du_compte_bancaire");
const QString YerothDatabaseTableColumn::INSTITUT_BANCAIRE("institut_bancaire");
const QString
YerothDatabaseTableColumn::
DESCRIPTION_DU_COMPTE_BANCAIRE("description_du_compte_bancaire");
const QString YerothDatabaseTableColumn::DESCRIPTION_CATEGORIE("description_categorie");
const QString YerothDatabaseTableColumn::NOM_CATEGORIE("nom_categorie");
const QString YerothDatabaseTableColumn::MONTANT_TVA("montant_tva");
const QString YerothDatabaseTableColumn::MONTANT_TVA_EN_GROS("montant_tva_en_gros");
const QString YerothDatabaseTableColumn::TVA("tva");
const QString YerothDatabaseTableColumn::MARGE_BENEFICIAIRE("marge_beneficiaire");
const QString
YerothDatabaseTableColumn::
MARGE_BENEFICIAIRE_EN_GROS("marge_beneficiaire_en_gros");
const QString YerothDatabaseTableColumn::MONTANT_RECU("montant_recu");
const QString YerothDatabaseTableColumn::MONTANT_A_REMBOURSER("montant_a_rembourser");
const QString YerothDatabaseTableColumn::MONTANT_TOTAL_VENTE("montant_total_vente");
const QString YerothDatabaseTableColumn::REMISE_PRIX("remise_prix");
const QString YerothDatabaseTableColumn::REMISE_POURCENTAGE("remise_pourcentage");
const QString YerothDatabaseTableColumn::LOCALISATION("localisation");
const QString YerothDatabaseTableColumn::LOCALISATION_STOCK("localisation_stock");
const QString YerothDatabaseTableColumn::QUANTITE_PAR_LOT("quantite_par_lot");
const QString YerothDatabaseTableColumn::LOTS_ENTRANT("lots_entrant");
const QString YerothDatabaseTableColumn::IMAGE_FOURNISSEUR("image_fournisseur");
const QString YerothDatabaseTableColumn::IMAGE_COMPTE_CLIENT("image_compte_client");
const QString YerothDatabaseTableColumn::IMAGE_PRODUIT("image_produit");
const QString YerothDatabaseTableColumn::DATE_PEREMPTION("date_peremption");
const QString YerothDatabaseTableColumn::DATE_DE_RECEPTION("date_de_reception");
const QString YerothDatabaseTableColumn::DATE_DE_COMMANDE("date_de_commande");
const QString YerothDatabaseTableColumn::DATE_ENTREE("date_entree");
const QString YerothDatabaseTableColumn::PRENOM("prenom");
const QString YerothDatabaseTableColumn::NOM("nom");
const QString YerothDatabaseTableColumn::NOM_RECEPTEUR("nom_recepteur");
const QString YerothDatabaseTableColumn::NOM_MAGASINIER("nom_magasinier");
const QString
YerothDatabaseTableColumn::
NOM_UTILISATEUR_MAGASINIER("nom_utilisateur_magasinier");
const QString
YerothDatabaseTableColumn::
NOM_UTILISATEUR_CAISSIER("nom_utilisateur_caissier");
const QString YerothDatabaseTableColumn::NOM_CAISSIER("nom_caissier");
const QString
YerothDatabaseTableColumn::
NOM_COMPLET_CREATEUR_REMISE_ALERTE("nom_complet_createur_remise_alerte");
const QString YerothDatabaseTableColumn::NOM_COMPLET("nom_complet");
const QString YerothDatabaseTableColumn::NOM_LOCALISATION("nom_localisation");
const QString YerothDatabaseTableColumn::NOM_UTILISATEUR("nom_utilisateur");
const QString YerothDatabaseTableColumn::STOCKS_ID("stocks_id");
const QString YerothDatabaseTableColumn::STOCK_MANAGER("stock_manager");
const QString YerothDatabaseTableColumn::MOT_PASSE("mot_passe");
const QString YerothDatabaseTableColumn::TITRE("titre");
const QString YerothDatabaseTableColumn::APPELATION_TITRE("appelation_titre");
const QString YerothDatabaseTableColumn::ROLE("role");
const QString YerothDatabaseTableColumn::NOM_ROLE("nom_role");
const QString YerothDatabaseTableColumn::EMAIL("email");
const QString YerothDatabaseTableColumn::REFERENCE_FOURNISSEUR("reference_fournisseur");
const QString YerothDatabaseTableColumn::REFERENCE_CLIENT("reference_client");
const QString YerothDatabaseTableColumn::NUMERO_TELEPHONE_1("numero_telephone_1");
const QString YerothDatabaseTableColumn::NUMERO_TELEPHONE_2("numero_telephone_2");
const QString YerothDatabaseTableColumn::LIEU_NAISSANCE("lieu_naissance");
const QString YerothDatabaseTableColumn::DATE_NAISSANCE("date_naissance");
const QString YerothDatabaseTableColumn::VILLE("ville");
const QString YerothDatabaseTableColumn::QUARTIER("quartier");
const QString YerothDatabaseTableColumn::PROVINCE_ETAT("province_etat");
const QString YerothDatabaseTableColumn::PAYS("pays");
const QString YerothDatabaseTableColumn::ADRESSE("adresse");
const QString YerothDatabaseTableColumn::ADRESSE_IP("adresse_ip");
const QString YerothDatabaseTableColumn::BOITE_POSTALE("boite_postale");
const QString YerothDatabaseTableColumn::STATUT_RESOLU("statut_resolu");
const QString YerothDatabaseTableColumn::SIEGE_SOCIAL("siege_social");
const QString YerothDatabaseTableColumn::NOTES("notes");
const QString YerothDatabaseTableColumn::NOM_ENTREPRISE("nom_entreprise");
const QString YerothDatabaseTableColumn::SECTEURS_DACTIVITES("secteurs_dactivites");
const QString
YerothDatabaseTableColumn::
REFERENCE_REGISTRE_DU_COMMERCE("reference_registre_du_commerce");
const QString YerothDatabaseTableColumn::NUMERO_CONTRIBUABLE("numero_contribuable");
const QString YerothDatabaseTableColumn::NOM_REPRESENTANT("nom_representant");
const QString YerothDatabaseTableColumn::NOM_ENTREPRISE_CLIENT("nom_entreprise_client");
const QString
YerothDatabaseTableColumn::
NOM_ENTREPRISE_FOURNISSEUR("nom_entreprise_fournisseur");
const QString YerothDatabaseTableColumn::DESCRIPTION_CLIENT("description_client");
const QString YerothDatabaseTableColumn::DESIGNATION("designation");
const QString YerothDatabaseTableColumn::DESIGNATION_REMISE("designation_remise");
const QString YerothDatabaseTableColumn::DESIGNATION_ALERTE("designation_alerte");
const QString YerothDatabaseTableColumn::CONDITION_ALERTE("condition_alerte");
const QString YerothDatabaseTableColumn::NOM_ENCAISSEUR("nom_encaisseur");
const QString YerothDatabaseTableColumn::DATE_PAIEMENT("date_paiement");
const QString YerothDatabaseTableColumn::MONTANT_PAYE("montant_paye");
const QString YerothDatabaseTableColumn::DATE_VENTE("date_vente");
const QString YerothDatabaseTableColumn::DATE_DEBUT("date_debut");
const QString YerothDatabaseTableColumn::DATE_FIN("date_fin");
const QString YerothDatabaseTableColumn::DATE_SORTIE("date_sortie");
const QString YerothDatabaseTableColumn::HEURE_PAIEMENT("heure_paiement");
const QString YerothDatabaseTableColumn::HEURE_VENTE("heure_vente");
const QString YerothDatabaseTableColumn::HEURE_SORTIE("heure_sortie");
const QString YerothDatabaseTableColumn::DESTINATAIRE("destinataire");
const QString
YerothDatabaseTableColumn::
NOM_COMPLET_DESTINATAIRE("nom_complet_destinataire");
const QString YerothDatabaseTableColumn::REMISE_NOTES("remise_notes");
const QString YerothDatabaseTableColumn::MESSAGE_ALERTE("message_alerte");
const QString YerothDatabaseTableColumn::DATE_CREATION("date_creation");
const QString YerothDatabaseTableColumn::TYPE_DE_PAIEMENT("type_de_paiement");
const QString YerothDatabaseTableColumn::TYPE_DE_VENTE("type_de_vente");
const QString YerothDatabaseTableColumn::NOTIFICATIONS("notifications");
const QString YerothDatabaseTableColumn::REMISE_RESOLUE("remise_resolue");
const QString YerothDatabaseTableColumn::ALERTE_RESOLUE("alerte_resolue");
const QString YerothDatabaseTableColumn::LOCALISATION_SORTIE("localisation_sortie");
const QString YerothDatabaseTableColumn::LOCALISATION_ENTREE("localisation_entree");
const QString YerothDatabaseTableColumn::LOCALISATION_SORTIE_ID("localisation_sortie_id");
const QString YerothDatabaseTableColumn::LOCALISATION_ENTREE_ID("localisation_entree_id");
